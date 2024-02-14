void setup() {
  // put your setup code here, to run once:
 int m1 =1;
 int m2 = -1;
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    
    for(int  i =1;i<=8;i++){

    digitalWrite(i-1,LOW);
    digitalWrite(i,HIGH);
    digitalWrite(i+1,HIGH);
    delay(100);

    
  }
  for(int j=8;j>=1;j--){

    digitalWrite(j+1,LOW);
    digitalWrite(j,HIGH);
    digitalWrite(j-1,HIGH);
    delay(100);

  }


}