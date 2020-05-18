#include <ArduinoJson.h>

const int currentPin = A0;
const int tempPin = A1;
const int voltagePin = A2;
const float analogRes = 0.00488758553;

int tempData[10];
int currentData[10];
int voltageData[10];


float flTemp, flCurrent, flVoltage;

DynamicJsonDocument doc(1024);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(4, OUTPUT);
}

void loop() {
  uint16_t avgCurrent = 0, avgTemp = 0,avgVoltage = 0;
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    avgCurrent += analogRead(currentPin);
    avgTemp += analogRead(tempPin);
    avgVoltage += analogRead(voltagePin);
    delay(50);
  }
  digitalWrite(4, HIGH);
  flCurrent = (((float)avgCurrent / 10) * analogRes);
  flTemp = (((float)avgTemp / 10) * analogRes) / 0.01;
  flVoltage = (((float)avgVoltage / 10) * analogRes);
  doc["amp"] = flCurrent;
  doc["temperature"] = flTemp;
  doc["voltage"] = flVoltage;
  serializeJson(doc, Serial);
  serializeJson(doc, Serial1);
  digitalWrite(4, LOW);
}
