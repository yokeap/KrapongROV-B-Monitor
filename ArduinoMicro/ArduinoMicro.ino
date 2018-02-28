#include <ArduinoJson.h>

const int currentPin = A0;
const int tempPin = A1;
const float analogRes = 0.00488758553;

int tempData[10];
int currentData[10];


float flTemp, flCurrent;

StaticJsonBuffer<100> jsonBuffer;

JsonObject& root = jsonBuffer.createObject();

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(115200);
  Serial1.begin(115200);
  pinMode(4, OUTPUT);
}

void loop() {
  int avgCurrent = 0, avgTemp = 0;
  // put your main code here, to run repeatedly:
  for(int i=0; i<10; i++){
    avgCurrent += analogRead(currentPin);
    avgTemp += analogRead(tempPin);
    delay(50);
  }
  digitalWrite(4, HIGH);
  flCurrent = ((avgCurrent / 10) * analogRes);
  flTemp = ((avgTemp / 10) * analogRes) / 0.01;
  root["amp"] = flCurrent;
  root["temperature"] = flTemp;
  root.printTo(Serial1);
  delay(500);
  digitalWrite(4, LOW);
//  Serial.print(flCurrent);
//  Serial.print(",  ");
//  Serial.print(flTemp);
//  Serial.println(",");
//  Serial1.print(flCurrent);
//  Serial1.print(",  ");
//  Serial1.print(flTemp);
//  Serial1.println(",");

}



