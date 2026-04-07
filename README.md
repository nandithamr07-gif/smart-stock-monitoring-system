#  Smart Stock Monitoring System

An IoT-based smart retail solution that monitors product stock in real-time using weight sensing and sends alerts when stock is low.

---

##  Project Overview

The Smart Stock Monitoring System is designed to automate inventory tracking in retail stores.
It uses a load cell to continuously measure product weight and an ESP32 to process data and send notifications via the Blynk app.

---

##  Hardware Components

* ESP32 Microcontroller
* HX711 Load Cell Amplifier
* Load Cell
* OLED Display (SSD1306)
* Buzzer
* LED Indicators
* Connecting Wires & Power Supply

---

##  Key Features

*  Real-time weight monitoring
*  Low stock alert via Blynk notification
*  Live display on OLED screen
*  Buzzer and LED indication for low stock
*  IoT-enabled remote monitoring
*  Sales trend estimation based on weight reduction

---

## Working Principle

1. The load cell detects the weight of products on the shelf.
2. HX711 converts the analog signal into digital data.
3. ESP32 processes the data and calculates current stock.
4. If the weight falls below a predefined threshold:

   * Blynk sends a notification
   * Buzzer and LED are triggered
5. Data is displayed on the OLED screen in real-time.

---

##  Technologies Used

* Embedded Systems
* Internet of Things (IoT)
* Arduino IDE
* Blynk IoT Platform

---



##  Future Enhancements

* Multi-shelf monitoring system
* Integration with billing system
* AI-based demand prediction
* Cloud data storage and analytics

---



