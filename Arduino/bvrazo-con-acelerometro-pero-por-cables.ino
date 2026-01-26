# Code
#include <Wire.h> 
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

// MPU
Adafruit_MPU6050 mpu;

// Servos
Servo servoBase;      
Servo servoBrazo;     
Servo servoAntebrazo; 

// Pines
#define SERVO_BASE_PIN 12
#define SERVO_BRAZO_PIN 13
#define SERVO_ANTE_PIN 14

// Posiciones actuales (suavizadas)
float posBase = 90;
float posBrazo = 90;
float posAnte = 90;

// Umbral y suavizado
const int umbral = 8;        // Menos sensible (sube a 10–12 si quieres más)
const float suavizado = 0.15; // 0.1 = muy suave | 0.3 = más rápido

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 20);

  if (!mpu.begin()) {
    Serial.println("❌ MPU6050 no detectado");
    while (1);
  }
  Serial.println("✅ MPU6050 OK");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  servoBase.attach(SERVO_BASE_PIN);
  servoBrazo.attach(SERVO_BRAZO_PIN);
  servoAntebrazo.attach(SERVO_ANTE_PIN);

  servoBase.write(90);
  servoBrazo.write(90);
  servoAntebrazo.write(90);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;

  int targetBase  = map(ax * 10, -100, 100, 0, 180);
  int targetBrazo = map(ay * 10, -100, 100, 0, 180);
  int targetAnte  = map(ay * 10, -100, 100, 180, 0);

  targetBase  = constrain(targetBase, 0, 180);
  targetBrazo = constrain(targetBrazo, 0, 180);
  targetAnte  = constrain(targetAnte, 0, 180);

  // Suavizado + zona muerta
  if (abs(targetBase - posBase) > umbral) {
    posBase += (targetBase - posBase) * suavizado;
  }
  if (abs(targetBrazo - posBrazo) > umbral) {
    posBrazo += (targetBrazo - posBrazo) * suavizado;
  }
  if (abs(targetAnte - posAnte) > umbral) {
    posAnte += (targetAnte - posAnte) * suavizado;
  }

  servoBase.write(posBase);
  servoBrazo.write(posBrazo);
  servoAntebrazo.write(posAnte);

  Serial.print("Base: "); Serial.print(posBase);
  Serial.print(" | Brazo: "); Serial.print(posBrazo);
  Serial.print(" | Ante: "); Serial.println(posAnte);

  delay(40);
}
