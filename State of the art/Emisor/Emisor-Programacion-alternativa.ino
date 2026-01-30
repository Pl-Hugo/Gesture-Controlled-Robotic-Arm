#include <Wire.h>
#include <WiFi.h>
#include <esp_now.h>
#include <math.h>

// ================= MPU6050 =================
#define MPU_ADDR 0x68

// ================= Datos a enviar =================
typedef struct {
  int base;
  int brazo;
  int ante;
} ControlData;

ControlData data;

// MAC del receptor
uint8_t receptorMAC[] = {0x00, 0x4B, 0x12, 0x34, 0x4D, 0x70};

// ================= Suavizado =================
float posBase = 90;
float posBrazo = 90;
float posAnte = 90;
const int umbral = 8;
const float suavizado = 0.15;

void setup() {
  Serial.begin(115200);
  delay(100);

  // I2C (los que te funcionan)
  Wire.begin(21, 22);   // SDA, SCL
  Wire.setClock(100000);

  // Wake up MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();

  Serial.println("MPU6050 listo");

  // ================= ESP-NOW =================
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error ESP-NOW");
    while (1);
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receptorMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Error agregando peer");
    while (1);
  }

  Serial.println("Emisor listo");
}

void loop() {
  // ===== Leer acelerómetro crudo =====
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // ACCEL_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  if (Wire.available() != 6) {
    Serial.println("Error lectura MPU");
    delay(40);
    return;
  }

  int16_t ax_raw = Wire.read() << 8 | Wire.read();
  int16_t ay_raw = Wire.read() << 8 | Wire.read();
  int16_t az_raw = Wire.read() << 8 | Wire.read();

  // Convertir a G (±2g -> 16384 LSB/g)
  float ax = ax_raw / 16384.0;
  float ay = ay_raw / 16384.0;
  float az = az_raw / 16384.0;

  // ===== Mapear a servos (ajusta rangos si hace falta) =====
  int targetBase  = map(ax * 100, -100, 100, 0, 180);
  int targetBrazo = map(ay * 100, -100, 100, 0, 180);
  int targetAnte  = map(ay * 100, -100, 100, 180, 0);

  targetBase  = constrain(targetBase, 0, 180);
  targetBrazo = constrain(targetBrazo, 0, 180);
  targetAnte  = constrain(targetAnte, 0, 180);

  // ===== Suavizado + zona muerta =====
  if (abs(targetBase - posBase) > umbral)
    posBase += (targetBase - posBase) * suavizado;

  if (abs(targetBrazo - posBrazo) > umbral)
    posBrazo += (targetBrazo - posBrazo) * suavizado;

  if (abs(targetAnte - posAnte) > umbral)
    posAnte += (targetAnte - posAnte) * suavizado;

  // Preparar datos
  data.base  = round(posBase);
  data.brazo = round(posBrazo);
  data.ante  = round(posAnte);

  // Enviar
  esp_err_t result = esp_now_send(receptorMAC, (uint8_t*)&data, sizeof(data));
  if (result != ESP_OK) Serial.println("Error enviando");

  // Debug
  Serial.print("AX: "); Serial.print(ax, 2);
  Serial.print(" AY: "); Serial.print(ay, 2);
  Serial.print(" -> Base: "); Serial.print(data.base);
  Serial.print(" Brazo: "); Serial.print(data.brazo);
  Serial.print(" Ante: "); Serial.println(data.ante);

  delay(40); // ~25 Hz
}
