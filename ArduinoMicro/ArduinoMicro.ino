const int currentPin = A0;
const int tempPin = A1;
const float analogRes = 0.00488758553;

int tempData[10];
int currentData[10];


float flTemp, flCurrent;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
  flCurrent = ((avgCurrent / 10) * analogRes) / 0.1;
  flTemp = ((avgTemp / 10) * analogRes) / 0.01;
  avgTemp = (avgTemp / 10);
  Serial.print(analogRead(flCurrent));
  Serial.print(",  ");
  Serial.print(flTemp);
  Serial.println(",");
  delay(500);
  digitalWrite(4, LOW);
}



