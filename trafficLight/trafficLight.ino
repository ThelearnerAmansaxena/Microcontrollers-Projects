//A> 11  B> 10  C>5  D>8  E> 9  F> 12  G>  13 dp>4



void setup() {
  // put your setup code here, to run once:
  // red
  pinMode(2,OUTPUT);
  // green
  pinMode(3,OUTPUT);
  //buzzer
  pinMode(6,OUTPUT);
  // for 7 segment to turn on 
  pinMode(7,OUTPUT);
  //for seven segment initialization
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  
  
}

void one() {
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  HIGH);
  digitalWrite(13, HIGH);
}

void two() {
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(5,  HIGH);
  digitalWrite(9,  LOW);
  digitalWrite(8,  LOW);
  digitalWrite(13, LOW);
}

void three() {
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  LOW);
  digitalWrite(13, LOW);
}

void four() {
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  HIGH);
  digitalWrite(13, LOW);
}

void five() {
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  LOW);
  digitalWrite(13, LOW);
}
void six() {
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(5,  LOW);
  digitalWrite(9,  LOW);
  digitalWrite(8,  LOW);
  digitalWrite(13, LOW);
}

void seven() {
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  HIGH);
  digitalWrite(13, HIGH);
}

void eight() {
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(5,  LOW);
  digitalWrite(9,  LOW);
  digitalWrite(8,  LOW);
  digitalWrite(13, LOW);
}

void nine() {
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(5,  LOW);
  digitalWrite(9,  HIGH);
  digitalWrite(8,  HIGH);
  digitalWrite(13, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3,0);
  digitalWrite(7,HIGH);
  digitalWrite(2,HIGH);
  nine();
  delay(1200);
  eight();
  delay(1200);
  seven();
  delay(1200);
  six();
  delay(1200);
  five();
  delay(1200);
  four();
  delay(1200);
  three();
  delay(1200);
  two();
  delay(1200);
  one();
  delay(1200);
  digitalWrite(7,LOW);
  analogWrite(3,20);
  delay(4000);
  digitalWrite(2,LOW);
  analogWrite(3,255);
  digitalWrite(6,HIGH);
  delay(3000);
  digitalWrite(6,LOW);
  analogWrite(3,0);
  delay(1000);





}
