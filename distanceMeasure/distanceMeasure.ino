#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
const int echopin = 11;
const int triggerpin = 10;




void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(triggerpin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   long distance , duration;
  digitalWrite(triggerpin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = (duration/2)/29.1;
  
  lcd.setCursor(0,0);
  lcd.print("distance is:" );
  lcd.setCursor(13,0);
  lcd.print(distance);
  delay(500);
  lcd.clear();

}
