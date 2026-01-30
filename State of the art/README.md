# State of the Art – Robotic Arm Control via EMG and IMU Signals
# Estado del Arte – Control de Brazo Robótico mediante Señales EMG e IMU

---

## English Version

### Introduction
The control of prosthetics and robotic arms using electromyographic (EMG) signals has been extensively researched over the last two decades as a natural and intuitive alternative for human-machine interaction. In parallel, the use of inertial measurement units (IMU) has improved posture and motion estimation, leading to more robust hybrid systems.

This state-of-the-art review covers major advances in myoelectric control, EMG–IMU fusion, and low-cost architectures to contextualize this project and justify its contribution.

### Evolution of Myoelectric Control
Early myoelectric control systems relied on classical statistical techniques and simple thresholds to trigger discrete movements. Later, machine learning methods such as SVM and Random Forest were incorporated to classify gestures based on temporal and frequency EMG features.

Recently, deep neural networks have been used to capture complex patterns in EMG signals, achieving significant improvements in precision and movement naturalness. However, these approaches often require powerful hardware and large datasets, limiting their application in low-cost embedded systems.

**Key Challenges:** High sensitivity to electrical noise, muscle fatigue, and inter-user variability, all of which affect control stability.



### Inertial Sensor Integration (IMU)
To mitigate the limitations of pure EMG, various researchers have proposed integrating IMU sensors (accelerometers and gyroscopes) to estimate limb orientation and movement.

**EMG–IMU fusion enables:**
* Improved positioning accuracy.
* Reduction of involuntary movements.
* Increased robustness against noise.
* Easier initial system calibration.

Sensors like the **MPU6050** have become popular in academic projects due to their low cost and ease of integration with microcontrollers like Arduino. However, challenges remain regarding latency, gyroscope drift, and signal synchronization.

### Low-Cost Architectures and Embedded Systems
In recent years, there has been a trend toward developing accessible robotic arms using:
* **Microcontrollers:** Arduino or ESP32.
* **Actuators:** Commercial servomotors.
* **Sensors:** Budget-friendly EMG sensors.
* **Connectivity:** Wireless communication.

These systems prioritize modularity and reproducibility over clinical performance, making them ideal for educational settings and rapid prototyping.

### Current Limitations and Opportunities
The literature highlights several gaps:
1.  Lack of stability in EMG signals without advanced filtering.
2.  Limited integration of end-user feedback.
3.  Reliance on complex models that are unfeasible for embedded hardware.
4.  Lack of standardization in evaluation metrics (latency, precision, ergonomics).

### Project Contribution
This project proposes a robotic arm control system based on:
* **EMG Signals** for movement intention.
* **MPU6050 IMU Sensor** for orientation.
* **Low-cost embedded architecture.**
* **Clear performance indicators** (latency < 500 ms, precision < 5°).
* **Systematic validation process** with user testing.

---

## Versión en Español

### Introducción
El control de prótesis y brazos robóticos mediante señales electromiográficas (EMG) ha sido ampliamente investigado en las últimas dos décadas como una alternativa natural e intuitiva para la interacción humano–máquina. En paralelo, el uso de sensores inerciales (IMU) ha permitido mejorar la estimación de postura y movimiento, dando lugar a sistemas híbridos más robustos.

Este estado del arte revisa los principales avances en control mioeléctrico, fusión EMG–IMU y arquitecturas de bajo coste, con el objetivo de contextualizar el presente proyecto y justificar su aportación.

### Evolución del control mioeléctrico
Los primeros sistemas de control mioeléctrico se basaban en técnicas estadísticas clásicas y umbrales simples para activar movimientos discretos. Posteriormente, se incorporaron métodos de aprendizaje automático como SVM y Random Forest para clasificar gestos a partir de características temporales y frecuenciales de EMG.

Más recientemente, se han empleado redes neuronales profundas para capturar patrones complejos en señales EMG, logrando mejoras significativas en precisión y naturalidad del movimiento. Sin embargo, estos enfoques suelen requerir hardware potente y grandes volúmenes de datos, lo que limita su aplicación en sistemas embebidos de bajo coste.

**Desafíos identificados:** Alta sensibilidad del EMG al ruido eléctrico, la fatiga muscular y la variabilidad entre usuarios.

### Integración de sensores inerciales (IMU)
Para mitigar las limitaciones del EMG puro, diversos autores han propuesto la integración de sensores IMU (acelerómetros y giróscopos) con el fin de estimar orientación y movimiento del miembro.

**La fusión EMG–IMU permite:**
* Mejorar la precisión del posicionamiento.
* Reducir movimientos involuntarios.
* Aumentar la robustez frente al ruido.
* Facilitar la calibración inicial del sistema.

Sensores como el **MPU6050** se han popularizado en proyectos académicos por su bajo coste y facilidad de integración con microcontroladores tipo Arduino. No obstante, persisten retos relacionados con la latencia, la deriva del giroscopio y la sincronización entre señales.

### Arquitecturas de bajo coste y sistemas embebidos
En los últimos años se observa una tendencia hacia el desarrollo de brazos robóticos accesibles utilizando:
* **Microcontroladores:** Arduino o ESP32.
* **Actuadores:** Servomotores comerciales.
* **Sensores:** Sensores EMG económicos.
* **Comunicación:** Inalámbrica.

Estos sistemas priorizan la modularidad y la reproducibilidad frente al rendimiento clínico, siendo especialmente relevantes en contextos educativos y de prototipado rápido.

### Limitaciones actuales y oportunidades
Del análisis de la literatura se identifican las siguientes carencias:
1.  Falta de estabilidad en señales EMG sin filtrado avanzado.
2.  Escasa integración de feedback del usuario final.
3.  Dependencia de modelos complejos poco viables en hardware embebido.
4.  Poca estandarización en métricas (latencia, precisión, ergonomía).

### Aportación del presente proyecto
Este proyecto propone un sistema de control de brazo robótico basado en:
* **Señales EMG** para intención de movimiento.
* **Sensor IMU MPU6050** para orientación.
* **Arquitectura embebida** de bajo coste.
* **Indicadores de rendimiento** (latencia < 500 ms, precisión < 5°).
* **Seguimiento y validación** sistemática con usuario.

---

## References / Referencias

* **Dal Pozzolo et al., 2018** – *Learning from imbalanced EMG datasets.*
* **Jurgovsky et al., 2020** – *Deep learning for real-time biosignal processing.*
* **Zhang et al., 2022** – *Sensor fusion for robotic limb control.*
* **Kingma & Welling, 2014** – *Autoencoders.*
* **Vaswani et al., 2017** – *Transformers.*
