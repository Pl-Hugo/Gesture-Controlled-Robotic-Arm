#include <ESP32Servo.h>
#include <esp_now.h>
#include <WiFi.h>

Servo servoX; // izquierda/derecha → pin 23
Servo servoY; // arriba/abajo → pin 19

typedef struct struct_message {
  int8_t ejeX;
  int8_t ejeY;
} struct_message;

struct_message datosRecibidos;

// Posición original
int posX = 90;
int posY = 90;

void OnDataRecv(const esp_now_recv_info * info, const uint8_t *incomingData, int len){
  memcpy(&datosRecibidos, incomingData, sizeof(datosRecibidos));

  // Mover servo X (izquierda/derecha)
  if(datosRecibidos.ejeX == 1) servoX.write(posX + 90);
  else if(datosRecibidos.ejeX == -1) servoX.write(posX - 90);
  else servoX.write(posX);

  // Mover servo Y (arriba/abajo)
  if(datosRecibidos.ejeY == 1) servoY.write(posY + 90);
  else if(datosRecibidos.ejeY == -1) servoY.write(posY - 90);
  else servoY.write(posY);
}

void setup() {
  Serial.begin(115200);

  servoX.attach(23);
  servoY.attach(19);

  servoX.write(posX);
  servoY.write(posY);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) Serial.println("Error inicializando ESP-NOW");

  esp_now_peer_info_t peerInfo = {};
  // MAC del emisor
  uint8_t macPeer[] = {0x00, 0x4B, 0x12, 0x34, 0x4D, 0x70};
  memcpy(peerInfo.peer_addr, macPeer, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);

  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("ESP32 RECEPTOR listo (servos + ESP-NOW)");
}

void loop() {}

