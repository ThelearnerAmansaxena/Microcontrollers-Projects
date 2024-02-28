// In this project i connected a LDR(photoresistor) with led and reading the voltage drop across ldr using arduino
// if the amount of light falling increase the led glows more and lcd display show in increase by +




#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float store = 0;
int i =6;
float reading = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600); 
  pinMode(A0,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0,0);
  lcd.print("POWER:");
   reading  = analogRead(A0);
  float volt = (5*reading)/1023;
 Serial.println(store);
 Serial.println("reading");
 Serial.println(reading);




  if(reading > store){

    lcd.setCursor(i,0);
    lcd.print("+");
    store = reading;
    i++;
  }
  if(i==13){
    lcd.clear();
    i=6;
    reading = 0;
    store = 0;
  }
  
delay(1000);
}
