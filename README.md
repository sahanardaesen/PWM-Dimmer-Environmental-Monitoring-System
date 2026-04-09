# 💡 Industrial Intelligence: Non-Blocking PWM Dimmer & Monitoring System

A high-performance embedded software prototype designed for industrial lighting control and safety monitoring. This project focuses on **Real-Time Responsiveness** by replacing standard `delay()` functions with a **Non-blocking (millis-based) architecture**, a critical requirement for safety-critical systems in defense and R&D sectors.

---

## 🚀 Key Features

* **Non-Blocking Logic:** The CPU remains 100% responsive. While the LCD updates at a steady 200ms rate, the analog signal processing and PWM control occur at full CPU speed.
* **Precision PWM Mapping:** High-resolution mapping of 10-bit Analog Input ($0-1023$) to 8-bit PWM Output ($0-255$) and 100-point Percentage Scale ($0-100\%$).
* **Smart Telemetry System:**
    * **Visual:** 16x2 I2C LCD displaying live brightness and system health status.
    * **Serial:** Real-time UART debugging for remote performance monitoring.
* **Automated Safety Protocol:**
    * **Normal:** Brightness $\le 90\%$.
    * **Critical:** Brightness $> 90\%$. Triggers visual "CRITICAL" alert on LCD and high-priority Serial warning.

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino Uno R3 (ATmega328P)
* **Input Device:** Linear Potentiometer
* **Display:** 16x2 LCD with I2C Module (PCF8574/MCP23008)
* **Actuator:** High-Intensity LED (PWM Driven)

---

## 📋 Connection Diagram

| Component | Arduino Pin | Mode |
| :--- | :--- | :--- |
| **Potentiometer (Center)** | A0 | Analog Input (ADC) |
| **Main LED** | Pin 9 | Digital Output (PWM) |
| **LCD SDA** | Pin A4 | I2C Data |
| **LCD SCL** | Pin A5 | I2C Clock |
| **Serial Link** | USB (D0/D1) | UART (9600 Baud) |

---

<img width="950" height="424" alt="image" src="https://github.com/user-attachments/assets/e8a431f2-1aec-4285-8a34-b33dc55a6629" />

---

<img width="979" height="754" alt="image" src="https://github.com/user-attachments/assets/9c2b3985-8548-4c62-af95-8f93a4174e54" />

---

<img width="1791" height="260" alt="image" src="https://github.com/user-attachments/assets/649df12c-b633-4d47-b0e6-ca3af7c1734e" />
