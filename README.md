# ESPecoMon ©
**Very** Low Cost Energy Monitoring using **Blynk**, **ESP8266** and **ACS712** with local **OTA** update facility. **Under $5** if you shop around for components.

I will try to keep this brief but remember **WORKING WITH MAINS ELECTRICITY CAN BE VERY DANGEROUS**. Hopefully the screenshot below explains what the Smartphone app does but if you have any questions take a look at the references on [Blynk's Community](https://community.blynk.cc/t/smart-energy-meters-what-are-they/16173/) site. 
![40W Soldering iron plugged in between left and right screenshots](https://github.com/pieman64/ESPecoMon/blob/master/ESPecoMonOFF2ON.png)
Obtain the **best** available iOT app builder from **Blynk** for your Smartphone:

[Android](https://play.google.com/store/apps/details?id=cc.blynk) and [iOS](https://itunes.apple.com/us/app/blynk-iot-for-arduino-rpi-particle-esp8266/id808760481?mt=8). 

Top up the 2000 **FREE** energy units to 3000 (costs less than a dollar) as this project requires 2600 units.

Manually install the [Blynk libraries](https://github.com/blynkkk/blynk-library/releases) for the [Arduino IDE](https://www.arduino.cc/en/Main/Software) 

Pick up a plug and play ESP8266 with 3.2V+ ADC:

[Sparkfun's Blynk Board](https://www.sparkfun.com/products/13794) 
[WeMos](https://www.aliexpress.com/item/WEMOS-D1-mini-Pro-16M-bytes-external-antenna-connector-ESP8266-WIFI-Internet-of-Things-development-board/32724692514.html)
[NodeMCU](https://www.aliexpress.com/item/1pcs-Wireless-module-NodeMcu-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266-CP2102-with-pcb/32720917001.html)

Select a 5A, 20A or [30A ACS712](https://www.aliexpress.com/item/30A-range-Current-Sensor-Module-ACS712-Module/1893200600.html) current sensor. We use the 30A module but we suspect you will get better accuracy from the lower rated modules if you are monitoring low current devices.

Flash your ESP8266 with [ESPecoMon.ino](https://github.com/pieman64/ESPecoMon/blob/master/ESPecoMon.ino) but don't forget to enter your credentials (Blynk token, SSID and PWD) before flashing.

Use the QR code below to load the project on to your Smartphone and away you go.
![Scan the QR code for ESPecuMon](https://github.com/pieman64/ESPecoMon/blob/master/QRforESPecoMon.png)

Arduino IDE Screenshot of Serial Monitor
![ESPecoMon Serial Monitor output](https://github.com/pieman64/ESPecoMon/blob/master/ESPecoMonSerialMonitor.PNG)

TODO:
1. Add Webhook widget for interfacing with well known API's
2. Log energy usage over time and add SuperGraph widget

If you want a more accurate Energy Monitoring system contact us at the [PeaceFairApp site](https://peacefairapp.com/)
____________________________________________________________________________
The answer, if you were asking, is [StackEdit](https://stackedit.io/)
