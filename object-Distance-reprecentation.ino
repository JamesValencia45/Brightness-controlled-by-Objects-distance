#include <LiquidCrystal.h>
const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigPin=13;
int echoPin=11;
int LedPin=A0;
float LedVal;
float pingTime;
float tagetDistance;
float speedOfSound=776.5;
String msg1="distance: ";
String msg2="in";
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin,LOW);

  pingTime=pulseIn(echoPin,HIGH);

  pingTime=pingTime/1000000.;
  pingTime=pingTime/3600.;
  
  tagetDistance=(speedOfSound*pingTime);
  tagetDistance=(tagetDistance/2);
  tagetDistance=(tagetDistance*63360);
  ledVal=(255./tagetDistance.);
  if (tagetDistance>255){
    ledVal=0;
  }
  if (tagetDistance<1){
    ledVal=255;
  }
  analogWrite(LedPin,ledVal);
  lcd.clear();
  lcd.print(msg1);
  lcd.print(tagetDistance);
  lcd.print(msg2);
  delay(1000);
}
