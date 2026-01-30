# Gesture-Controlled-Robotic-Arm
### Development of a biomimetic prosthetic hand and arm control system using ESP32

## Abstract
This project presents an intuitive control system for a robotic arm and prosthetic hand, designed for applications in industrial robotics, teleoperation, and assistive technology. The primary objective is to transcend traditional rigid interfaces by implementing a natural Human-Machine Interaction (HMI) based on the user's physiological and kinematic data.

The system architecture is built upon two technological pillars:
* **Inertial Measurement (IMU/Accelerometers):** Captures the operator's orientation and angular displacement, enabling the robot to replicate arm movements in real-time (mirroring).
* **Electromyography (EMG) Sensors:** Detects muscle electrical activity to provide proportional control over the gripper's opening and closing mechanisms.

A key innovation of this project is the distributed processing system using **dual ESP32 microcontrollers** linked via the **ESP-NOW protocol**. This configuration ensures ultra-low latency (under 500ms) and high-speed data transmission without the overhead of traditional network infrastructures, proving the feasibility of high-performance, low-cost teleoperation in hazardous environments or ergonomic assistance.

---

## Resumen
Este proyecto desarrolla un sistema de control intuitivo para un brazo robótico y mano protésica, orientado a la robótica industrial, teleoperación y tecnologías de asistencia. El objetivo central es superar las interfaces rígidas tradicionales mediante la implementación de una Interacción Hombre-Máquina (HMI) natural, basada en los datos fisiológicos y cinemáticos del usuario.

El sistema se fundamenta en dos ejes tecnológicos principales:
* **Medición Inercial (IMU/Acelerómetros):** Capturan la orientación y el movimiento angular del operario, permitiendo que el robot replique estas acciones en tiempo real (mirroring).
* **Sensores EMG:** Detectan la actividad eléctrica muscular para controlar de forma precisa la apertura y cierre de la pinza o mano.

Una innovación clave de este proyecto es el sistema de procesamiento distribuido mediante **dos microcontroladores ESP32** vinculados a través del protocolo **ESP-NOW**. Esta configuración garantiza una latencia ultra baja (menor a 500ms) y una transmisión de datos de alta velocidad sin la carga de las infraestructuras de red tradicionales, demostrando la viabilidad de soluciones de telecontrol de alto rendimiento y bajo coste para entornos peligrosos o asistencia ergonómica.

## License
[Insertar tipo de licencia, ej: MIT]