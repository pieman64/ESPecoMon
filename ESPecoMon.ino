/* ESPecoMon.ino very low cost energy monitor using ACS712
 * References to WeMos should also apply to Sparkfun Blynk board and nodeMCU
 * WeMos connections VCC to 5V, GND to GND and OUT to A0
 * WeMos 5V pin is approx 4.8V and ACS712 requires at least 4.5V so don't use WeMos 3.3V to power the ACS712
 * WeMos only has a 3.2V ADC so you have 2 options:
 * 1. Only use 60% of the current rating of the ACS712
 * or
 * 2. Add a 180K Ohm resistor between ACS712 data out and Analogue port A0
 */
 
//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define CLOUD  // comment out for local server

BlynkTimer timer;

char auth[]       = "xxxx";
char ssid[]       = "xxxx";
char pass[]       = "xxxx";
char server[]     = "blynk-cloud.com";    // ip or domain
char myhostname[] = "ACS712-5A-20A-30A";  // for OTA and router identification

const int sensorIn = A0;
unsigned int mVperAmp = 66;   // 185 for 5A, 100 for 20A and 66 for 30A Module
float ACSVoltage = 0;
float VRMS = 0;
float AmpsRMS = 0;
float inputV = 238.0;           // reading from DMM
float mcuVoltage = 5.0;         // MCU ADC maximum - voltage divider means we should use 5.0V reference not 3.2V
float WH = 0;
unsigned int calibration = 62;  // V2 slider calibrates this
unsigned int pF = 95;           // Power Factor default 90
float energyCostpermonth = 0;   // 30 day cost as present energy usage incl approx PF 
unsigned int energyTariff = 1437; // http://www.energysavingtrust.org.uk/about-us/our-calculations

void getACS712() {  // for AC
  ACSVoltage = getVPP();
  VRMS = (ACSVoltage/2.0) *0.707; 
  VRMS = VRMS - (calibration / 10000.0);     // calibtrate to zero with slider
  AmpsRMS = (VRMS * 1000)/mVperAmp;
  if((AmpsRMS > -0.015) && (AmpsRMS < 0.008)){  // remove low end chatter
    AmpsRMS = 0.0;
  }
  Serial.print(String(AmpsRMS, 3));
  Serial.print(" Amps RMS");
  Serial.print("\tPower: ");  
  WH = (inputV * AmpsRMS) * (pF / 100.0);  
  Serial.print(String(WH, 3)); 
  Serial.print(" WH"); 
  Blynk.virtualWrite(V0, String(AmpsRMS, 3));
  Blynk.virtualWrite(V1, String(WH, 3));
  Blynk.virtualWrite(V3, int(WH + 0.5));  // gauge
  energyCostpermonth = 24.0 * 30.0 * (WH / 1000.0) * (energyTariff / 10000.0);
  Serial.print("  Approx cost per month: £"); 
  Serial.println(String(energyCostpermonth, 2));
  Blynk.virtualWrite(V6, String(energyCostpermonth, 2));
}

float getVPP()
{
  float result; 
  int readValue;                
  int maxValue = 0;             
  int minValue = 1024;          
  uint32_t start_time = millis();
  while((millis()-start_time) < 950) //read every 0.95 Sec
  {
     readValue = analogRead(sensorIn);    
     if (readValue > maxValue) 
     {         
         maxValue = readValue; 
     }
     if (readValue < minValue) 
     {          
         minValue = readValue;
     }
  } 
   result = ((maxValue - minValue) * mcuVoltage) / 1024.0;  
   return result;
 }

// V0 AC IRMS display
// V1 WH display

BLYNK_WRITE(V2) {  // calibration slider 50 to 70
    calibration = param.asInt();
}

// V3 WH gauge

BLYNK_WRITE(V4) {  // set supply voltage slider 70 to 260
    inputV = param.asInt();
}

BLYNK_WRITE(V5) {  // set 5, 20 or 30A ACS712 with menu
    switch (param.asInt())
    {
      case 1: {       // 30A
        mVperAmp = 66;
        break;
      }
      case 2: {       // 20A
        mVperAmp = 100;
        break;
      }
      case 3: {       // 5A
        mVperAmp = 185;
        break;
      }
      default: {      // 30A
       mVperAmp = 66;
      }
    }
}

// V6 Cost gauge

BLYNK_WRITE(V7) {  // PF slider 60 to 100 i.e 0.60 to 1.00, default 95
    pF = param.asInt();
}

BLYNK_WRITE(V8) {  // Energy tariff slider 1000 to 2000, default 1437 (UK £ 0.1437 / KWH)
    energyTariff = param.asInt();
}

void setup() { 
  WiFi.hostname(myhostname);
  Serial.begin(115200); 
  Serial.println("\n Rebooted");
  WiFi.mode(WIFI_STA);
  #ifdef CLOUD
    Blynk.begin(auth, ssid, pass);
  #else
    Blynk.begin(auth, ssid, pass, server);
  #endif
  while (Blynk.connect() == false) {}
  ArduinoOTA.setHostname(myhostname);
  ArduinoOTA.begin();
  timer.setInterval(2000L, getACS712); // get data every 2s
}

BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

void loop() {
  Blynk.run();
  ArduinoOTA.handle();
  timer.run();
}
