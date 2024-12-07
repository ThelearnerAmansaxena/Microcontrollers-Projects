#include "lcd.h"

void setup() {

  Serial.begin(9600);
// sample character byte array to print custom character
  byte customChar[] = {
    B01110,
    B01010,
    B01110,
    B11011,
    B00100,
    B00100,
    B11111,
    B00100
  };
// use this to print above custom char: printCustom(customChar);

  lcdBegin();
  setCursor(0);
  cursorPos(1,1);
  printText("SUM: 4+19 =");
  sum(4,19);

}

void loop() {
  
  
  
}
