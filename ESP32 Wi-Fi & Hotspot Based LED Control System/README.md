ESP32 Wi-Fi & Hotspot Based LED Control System

Overview
This project enables wireless control of an LED using ESP32 through a smartphone. The system works in both Wi-Fi Station mode (connected to external Wi-Fi) and Access Point mode (ESP32 hotspot), ensuring flexible control with or without internet.

Objective
To control LED wirelessly using a mobile phone  
To support both Wi-Fi network and standalone hotspot modes  
To provide flexible IoT control without dependency on external internet  

Technologies Used
- ESP32 Microcontroller  
- Embedded C / Arduino IDE  
- Wi-Fi (Station + Access Point Mode)  
- Web Server (IP-based control)  

Working Principle
- ESP32 creates a web server  
- User connects:
  Either via Wi-Fi network  
  Or ESP32 hotspot  
- User enters IP address in browser  
- LED is controlled via web interface (ON/OFF buttons)  

Features
- Dual mode operation (Wi-Fi + Hotspot)  
- Real-time LED control  
- No internet required (AP mode)  
- Simple web-based interface  
