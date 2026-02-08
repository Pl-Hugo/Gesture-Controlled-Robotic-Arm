# Receptor

#include <ESP32Servo.h>
#include <esp_now.h>
#include <WiFi.h>

// ===== Servos =====
Servo servoBrazo; // pin 23
Servo servoBase;  // pin 19
Servo servoAnte;  // pin 18

// ===== Estructura IGUAL al emisor =====
typedef struct {
  int base;
  int brazo;
  int ante;
} ControlData;

ControlData datosRecibidos;

// ===== Callback ESP-NOW =====
void OnDataRecv(const esp_now_recv_info * info, const uint8_t *incomingData, int len) {
  if (len != sizeof(ControlData)) return; // seguridad

  memcpy(&datosRecibidos, incomingData, sizeof(datosRecibidos));

  // Mover servos directamente
  servoBase.write(constrain(datosRecibidos.base, 0, 180));
  servoBrazo.write(constrain(datosRecibidos.brazo, 0, 180));
  servoAnte.write(constrain(datosRecibidos.ante, 0, 180));

  // Debug
  Serial.print("Base: ");
  Serial.print(datosRecibidos.base);
  Serial.print("  Brazo: ");
  Serial.print(datosRecibidos.brazo);
  Serial.print("  Ante: ");
  Serial.println(datosRecibidos.ante);
}

void setup() {
  Serial.begin(115200);

  // ===== Attach servos =====
  servoBrazo.attach(23);
  servoBase.attach(19);
  servoAnte.attach(18);

  // Posición inicial
  servoBase.write(90);
  servoBrazo.write(90);
  servoAnte.write(90);

  // ===== ESP-NOW =====
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error inicializando ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("ESP32 RECEPTOR listo (Base / Brazo / Ante)");
}

void loop() {
  // vacío
}
