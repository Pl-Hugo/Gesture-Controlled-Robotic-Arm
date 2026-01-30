# Emisor

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <esp_now.h>
#include <WiFi.h>

Adafruit_MPU6050 mpu;

// MAC del receptor
uint8_t macReceptor[] = {0x78, 0xE3, 0x6D, 0x17, 0x70, 0x00};

// Estructura de datos: dos ejes
typedef struct struct_message {
  int8_t ejeX; // izquierda/derecha: -1,0,1
  int8_t ejeY; // arriba/abajo: -1,0,1
} struct_message;

struct_message datosEnviar;

void setup() {
  Serial.begin(115200);

  // Inicializar MPU6050
  if (!mpu.begin()) {
    Serial.println("Error inicializando MPU6050");
    while (1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) Serial.println("Error inicializando ESP-NOW");

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, macReceptor, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) Serial.println("Error añadiendo peer");

  Serial.println("ESP32 EMISOR listo (MPU6050 + ESP-NOW)");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Valores de aceleración en g
  float ax = a.acceleration.x; // izquierda/derecha
  float ay = a.acceleration.y; // arriba/abajo

  // Ajustar a -1,0,1 según umbral
  int8_t ejeX = 0;
  int8_t ejeY = 0;
  float umbral = 2.0; // g, ajustar según sensibilidad

  if (ax > umbral) ejeX = 1;       // derecha
  else if (ax < -umbral) ejeX = -1; // izquierda

  if (ay > umbral) ejeY = 1;       // arriba
  else if (ay < -umbral) ejeY = -1; // abajo

  datosEnviar.ejeX = ejeX;
  datosEnviar.ejeY = ejeY;

  esp_now_send(macReceptor, (uint8_t*)&datosEnviar, sizeof(datosEnviar));

  delay(100); // enviar cada 100ms
}
