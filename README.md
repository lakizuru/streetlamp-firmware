# Multifunctional Smart IoT Streetlamp System - Firmware

This repository contains the code for device firmware of the Multifunctional Smart IoT Streetlamp System. It is developed using Arduino language. It connects to Firebase Realtime database for data store and retrieval purposes. 

This repository is related to the [frontend repository](https://github.com/lakizuru/streetlamp-frontend) of this project.

This was developed for an undergraduate project as a fulfillment to our BSc. (Hons) in IT degree program. Project is completed 100%.

## System Overview

<img src="Docs\Overview.jpg" alt="Overview Diagram"/>

This firmware is flashed to the NodeMCU development board which will be fixed to the streetlamp embedded system. A PIR sensor and a LDR is connected to the NodeMCU as input peripherals. As output peripherals, a LED strip is connected.

NodeMCU will be connected to a specified (hard coded) WiFi network to maintain the connectivity to Firebase Realtime database.

## Development

This code was developed using Arduino IDE. 

### Libraries Used
- FirebaseArduino
- Adafruit_NeoPixel
- ESP8266WiFi