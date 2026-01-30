# Reference / Referencia: https://github.com/hang-yin/IMUnipulator

---

# Technical Differentiation

This project is positioned within the field of biomimetic control for robotic limbs. As a fundamental part of the research and development process, the project [IMUnipulator by hang-yin](https://github.com/hang-yin/IMUnipulator) has been taken as a reference, as it represents a solid foundation in the use of inertial and muscular sensors.

### Technical Similarities
Both projects share a high-precision sensor architecture to capture human movement intent:
* **EMG Sensor:** For muscle signal detection and function activation.
* **Accelerometer / IMU:** For real-time arm movement and orientation tracking.

### Improvements and Innovations (Differentiation)
This implementation introduces critical optimizations in communication and processing architecture, achieving a more robust and reactive system:

1. **Dual ESP32 Architecture:** Unlike the reference implementation, this system utilizes two ESP32 microcontrollers working in parallel.
    * **Transmitter Node:** Dedicated exclusively to capturing, filtering, and processing signals (EMG/IMU).
    * **Receiver Node:** Dedicated to motor control logic and kinematics.
2. **ESP-NOW Protocol:** Standard Wi-Fi or Bluetooth connections are replaced by ESP-NOW (utilizing the Wi-Fi band at the MAC layer). This allows for a direct device-to-device connection without the need for a router.
3. **Ultra-Low Latency:** Thanks to direct communication and distributed processing, the system achieves a response time of less than 500ms. This ensures that the robotic arm movements are fluid and occur almost simultaneously with the human movement.

---

# Diferenciación Técnica

Este proyecto se sitúa en el campo del control biomimético de extremidades robóticas. Como parte fundamental del proceso de investigación y desarrollo, se ha tomado como referencia el proyecto [IMUnipulator de hang-yin](https://github.com/hang-yin/IMUnipulator), el cual representa una base sólida en el uso de sensores inerciales y musculares.

### Similitudes Técnicas
Ambos proyectos comparten una arquitectura de sensores de alta precisión para capturar la intención del movimiento humano:
* **Sensor EMG:** Para la detección de señales musculares y activación de funciones.
* **Acelerómetro / IMU:** Para el rastreo de movimiento y orientación del brazo en tiempo real.

### Mejoras e Innovaciones (Diferenciación)
Esta implementación introduce optimizaciones críticas en la arquitectura de comunicación y procesamiento, logrando un sistema más robusto y reactivo:

1. **Arquitectura Dual ESP32:** A diferencia de la implementación de referencia, este sistema utiliza dos microcontroladores ESP32 trabajando en paralelo.
    * **Nodo Emisor:** Dedicado exclusivamente a la captura, filtrado y procesamiento de señales (EMG/IMU).
    * **Nodo Receptor:** Dedicado a la lógica de control de motores y cinemática.
2. **Protocolo ESP-NOW:** Se sustituyen las conexiones Wi-Fi estándar o Bluetooth por ESP-NOW (que utiliza la banda Wi-Fi a nivel de capa MAC). Esto permite una conexión directa entre dispositivos sin necesidad de un router.
3. **Ultra-Baja Latencia:** Gracias a la comunicación directa y al procesamiento distribuido, se logra una respuesta menor a 500ms. Esto garantiza que los movimientos del brazo robótico sean fluidos y ocurran prácticamente al mismo tiempo que el movimiento humano.
