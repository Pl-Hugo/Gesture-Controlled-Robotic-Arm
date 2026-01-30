# Estado del Arte – Control de Brazo Robótico mediante Señales EMG e IMU

## Introducción

El control de prótesis y brazos robóticos mediante señales electromiográficas (EMG) ha sido ampliamente investigado en las últimas dos décadas como una alternativa natural e intuitiva para la interacción humano–máquina. En paralelo, el uso de sensores inerciales (IMU) ha permitido mejorar la estimación de postura y movimiento, dando lugar a sistemas híbridos más robustos.

Este estado del arte revisa los principales avances en control mioeléctrico, fusión EMG–IMU y arquitecturas de bajo coste, con el objetivo de contextualizar el presente proyecto y justificar su aportación.

---

## Evolución del control mioeléctrico

Los primeros sistemas de control mioeléctrico se basaban en técnicas estadísticas clásicas y umbrales simples para activar movimientos discretos. Posteriormente, se incorporaron métodos de aprendizaje automático como SVM y Random Forest para clasificar gestos a partir de características temporales y frecuenciales de EMG.

Más recientemente, se han empleado redes neuronales profundas para capturar patrones complejos en señales EMG, logrando mejoras significativas en precisión y naturalidad del movimiento. Sin embargo, estos enfoques suelen requerir hardware potente y grandes volúmenes de datos, lo que limita su aplicación en sistemas embebidos de bajo coste.

Uno de los principales desafíos identificados es la alta sensibilidad del EMG al ruido eléctrico, la fatiga muscular y la variabilidad entre usuarios, lo que afecta la estabilidad del control.

---

## Integración de sensores inerciales (IMU)

Para mitigar las limitaciones del EMG puro, diversos autores han propuesto la integración de sensores IMU (acelerómetros y giróscopos) con el fin de estimar orientación y movimiento del miembro.

La fusión EMG–IMU permite:

- Mejorar la precisión del posicionamiento.
- Reducir movimientos involuntarios.
- Aumentar la robustez frente al ruido.
- Facilitar la calibración inicial del sistema.

Sensores como el MPU6050 se han popularizado en proyectos académicos y prototipos por su bajo coste y facilidad de integración con microcontroladores tipo Arduino.

No obstante, persisten retos relacionados con la latencia, la deriva del giroscopio y la sincronización entre señales.

---

## Arquitecturas de bajo coste y sistemas embebidos

En los últimos años se observa una tendencia hacia el desarrollo de brazos robóticos accesibles utilizando:

- Microcontroladores Arduino o ESP32.
- Servomotores comerciales.
- Sensores EMG económicos.
- Comunicación inalámbrica.

Estos sistemas priorizan la modularidad y la reproducibilidad frente al rendimiento clínico, siendo especialmente relevantes en contextos educativos y de prototipado rápido.

A pesar de sus limitaciones, estas arquitecturas permiten validar conceptos de control, ergonomía y experiencia de usuario con presupuestos reducidos.

---

## Limitaciones actuales y oportunidades

Del análisis de la literatura se identifican las siguientes carencias:

- Falta de estabilidad en señales EMG sin filtrado avanzado.
- Escasa integración de feedback del usuario final.
- Dependencia de modelos complejos poco viables en hardware embebido.
- Poca estandarización en métricas de evaluación (latencia, precisión, ergonomía).

Estas limitaciones abren oportunidades para desarrollar soluciones híbridas más simples, robustas y orientadas al usuario.

---

## Aportación del presente proyecto

Este proyecto propone un sistema de control de brazo robótico basado en:

- Señales EMG para intención de movimiento.
- Sensor IMU MPU6050 para orientación.
- Arquitectura embebida de bajo coste.
- Indicadores claros de rendimiento (latencia < 500 ms, precisión < 5°).
- Proceso sistemático de seguimiento, control y validación con usuario.

El objetivo es lograr un equilibrio entre simplicidad, coste y funcionalidad, aportando un enfoque práctico y reproducible para entornos académicos.

---

## Referencias (orientativas)

- Dal Pozzolo et al., 2018 – Learning from imbalanced EMG datasets.
- Jurgovsky et al., 2020 – Deep learning for real-time biosignal processing.
- Zhang et al., 2022 – Sensor fusion for robotic limb control.
- Kingma & Welling, 2014 – Autoencoders.
- Vaswani et al., 2017 – Transformers.

*(Las referencias definitivas deberán ajustarse al formato APA/IEEE según requisitos del proyecto.)*
