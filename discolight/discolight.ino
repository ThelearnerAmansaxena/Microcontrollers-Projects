void setup() {
  // put your setup code here, to run once:
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
  //1 led
  for(int i=1; i<=8;i++){
    digitalWrite(i-1,LOW);
    digitalWrite(i,HIGH);
    delay(350);


  }
  for(int j=8; j>=1;j--){
    digitalWrite(j+1,LOW);
    digitalWrite(j,HIGH);
    delay(350);
  }
//2 led pair

for(int i=1; i<=8;i+=2){
  digitalWrite(i,HIGH);
  digitalWrite(i+1,HIGH);
  delay(400);
  digitalWrite(i,LOW);
  digitalWrite(i+1,LOW);
}

for(int j=8;j>=1;j-=2){
  digitalWrite(j,HIGH);
  digitalWrite(j-1,HIGH);
  delay(400);
  digitalWrite(j,LOW);
  digitalWrite(j-1,LOW);
}

//3led pair
for(int i=1; i<=8;i+=3){
  digitalWrite(i,HIGH);
  digitalWrite(i+1,HIGH);
  digitalWrite(i+2,HIGH);
  delay(550);
  digitalWrite(i,LOW);
  digitalWrite(i+1,LOW);
  digitalWrite(i+2,LOW);
}

for(int j=8;j>=1;j-=3){
  digitalWrite(j,HIGH);
  digitalWrite(j-1,HIGH);
  digitalWrite(j-2,HIGH);
  delay(550);
  digitalWrite(j,LOW);
  digitalWrite(j-1,LOW);
  digitalWrite(j-2,LOW);
}

// 4led pair


for(int i=1; i<=8;i+=4){
  digitalWrite(i,HIGH);
  digitalWrite(i+1,HIGH);
  digitalWrite(i+2,HIGH);
  digitalWrite(i+3,HIGH);
  delay(650);
  digitalWrite(i,LOW);
  digitalWrite(i+1,LOW);
  digitalWrite(i+2,LOW);
  digitalWrite(i+3,LOW);
}

for(int j=8;j>=1;j-=4){
  digitalWrite(j,HIGH);
  digitalWrite(j-1,HIGH);
  digitalWrite(j-2,HIGH);
  digitalWrite(j-3,HIGH);
  delay(650);
  digitalWrite(j,LOW);
  digitalWrite(j-1,LOW);
  digitalWrite(j-2,LOW);
  digitalWrite(j-3,LOW);
}













}
