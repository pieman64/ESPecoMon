# ESPecoMon
Very Low Cost Energy Monitoring with Blynk, ESP8266 and ACS712.

I will try to keep this brief but remember WORKING WITH MAINS ELECTRICTY CAN BE VERY DANGEROUS.

Obtain the best available iOT app builder from Blynk for your Smartphone:

Android https://play.google.com/store/apps/details?id=cc.blynk and 
iOS https://itunes.apple.com/us/app/blynk-iot-for-arduino-rpi-particle-esp8266/id808760481?mt=8

Install the Blynk libraries (MANUALLY) from https://github.com/blynkkk/blynk-library/releases

Pick up a plug and play ESP8266 with 3.2+ ADC:

Sparkfun's Blynk Board: https://www.sparkfun.com/products/13794 
WeMos: https://www.aliexpress.com/item/WEMOS-D1-mini-Pro-16M-bytes-external-antenna-connector-ESP8266-WIFI-Internet-of-Things-development-board/32724692514.html
NodeMCU: https://www.aliexpress.com/item/1pcs-Wireless-module-NodeMcu-Lua-WIFI-Internet-of-Things-development-board-based-ESP8266-CP2102-with-pcb/32720917001.html

Lastly, select a 5A, 20A or 30A ACS712 current sensor. We use the 30A module but we suspect you will get better accuracy from the lower rates modules if you are monitoring low current devices. https://www.aliexpress.com/item/30A-range-Current-Sensor-Module-ACS712-Module/1893200600.html

Flash your ESP8266 with ESPecoMon.ino

Use the QR code / url to load the project on to your Smartphone and away you go.

TODO:

1. Add QR code and url for Blynk project
2. Add Smartphone screenshots
3. Add Serial Monitor screenshot
4. Few more notes etc
