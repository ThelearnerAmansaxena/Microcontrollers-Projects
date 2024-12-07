volatile uint8_t *portf, *portk, *outf, *outk;
char command = 0x80;
int check = 0,  length = 16, count = 0, m,endValue = 0;
byte customChar1[]{
  0b00100,
  0b01110,
  0b11111,
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100
 };
 
 byte customChar2[] = {
  B00100,
  B00100,
  B11111,
  B01110,
  B00100,
  B00100,
  B00100,
  B00100
};

 byte customChar3[] = {
  B01110,
  B01010,
  B01110,
  B10001,
  B10001,
  B11111,
  B01010,
  B01010
};
void Delay(volatile long int value) {
  for (volatile long int j = 0; j < value * 10; j++);
  return;
}

void portSetup() {
  // Corrected initialization with proper addresses
  portf = (volatile uint8_t *) 0x30;
  portk = (volatile uint8_t *) 0x107;
  outf = (volatile uint8_t *) 0x31;
  outk = (volatile uint8_t *) 0x108;

  // Set port direction to output
  *portf = 0xFF;
  *portk = 0xFF;

  return;
}

void takeCommand(char command) {
  *outf = command;
  return;
}

void recieveCommand() {
  *outk = 0x02;   // rs 0 and enable 1
  Delay(100);
  *outk = 0x00;   // enable 0
  return;
}

void recieveData() {
  *outk = 0x03;
  Delay(100);
  *outk = 0x00;
  return;
}

void writeLcd(char data) {
  *outf = data;
  return;
}

void clearDisplay() {
  takeCommand(0x01);  // clear display
  recieveCommand();
  return;
}

void lcdBegin() {
  portSetup();
  takeCommand(0x38);  // 8bit 2 line
  recieveCommand();

  takeCommand(0x0C);  // turn on displayS
  recieveCommand();

  takeCommand(0x01);  // clear display
  recieveCommand();
  return;
}

void cursorPos(int i, int k) {
  endValue = k;
  m =i;
  
  if (i == 1) {
    command = 127 + k;
  
  } else if (i == 2) {
    command = 191 + k;
  
  }
  takeCommand(command);
  recieveCommand();
  return;
}

void setCursor(int a) {
  if (a == 1) {
    takeCommand(0x0F);
    recieveCommand();
  } else if (a == 0) {
    takeCommand(0x0C);
    recieveCommand();
  }
  return;
}

void moveDisplay(int b) {
  if (b == 1) {
    takeCommand(0x1C);  // move right
    recieveCommand();
  } else if (b == 0) {
    takeCommand(0x18); // move left
    recieveCommand();
  }
  return;
}

void printCustom(byte character[]) {
  for(int i=0;i<8;i++){
    Serial.println(character[i]);
  }
  if (check > 32) {
    return;
  }
  takeCommand(0x58 + check);
  recieveCommand();
  for (int j = 0; j < 8; j++) {
    writeLcd(character[j]);
    recieveData();
  }

  takeCommand(0x02);  // return home
  recieveCommand();
  takeCommand(command);
  recieveCommand();
  writeLcd(3 + count);
  recieveData();
  check += 8;
  count++;
  return;
}

void printMan() {
  takeCommand(0x40);
  recieveCommand();
  for (int j = 0; j < 8; j++) {
    writeLcd(customChar3[j]);
    recieveData();
  }

  takeCommand(0x02);  // return home
  recieveCommand();
  takeCommand(command);
  recieveCommand();
  writeLcd(0);
  recieveData();
  return;
}

void printSword() {
 
  takeCommand(0x48);
  recieveCommand();
  for (int i = 0; i < 8; i++) {
  writeLcd(customChar2[i]);
  recieveData();
 
  }

  takeCommand(0x02);  // return home
  recieveCommand();
  takeCommand(command);
  recieveCommand();
  writeLcd(1);
  recieveData();
  return;
}

void printDumbbell() {
  takeCommand(0x50);
  recieveCommand();
  for (int j = 0; j < 8; j++) {
    writeLcd(customChar1[j]);
    recieveData();
  }

  takeCommand(0x02);  // return home
  recieveCommand();
  takeCommand(command);
  recieveCommand();
  writeLcd(2);
  recieveData();
  return;
}

void printText(char text[]) {
  int i = 0;
  while (text[i] != 0) {
    if(endValue+i>length && m==1){
      cursorPos(2,1);
      length = 1000;
     
    }
    writeLcd(text[i]);
    recieveData();
    Delay(100);
    i++;
  }
  return;
}
   
  void sum(int a ,int b){
  int sum=0,temp=0,i=0;
  char result[10];
  sum = a+b;
  temp = sum;
  
  Serial.println(sum);
  while(temp!=0){
    
    result[i] = temp%10+48;
    temp/=10;
    i++;
  }
  
  for(int j=i-1;j>=0;j--){
    writeLcd(result[j]);
    recieveData();
  }
    return;
  }

void diff(int a,int  b){

int diff=0,temp=0,i=0;
  char result[10];
  diff = a-b;
  temp = diff;
  
  Serial.println(diff);
  while(temp!=0){
    
    result[i] = temp%10+48;
    temp/=10;
    i++;
  }
  
  for(int j=i-1;j>=0;j--){
    writeLcd(result[j]);
    recieveData();
  }

    return;
  }
void product(int a,int  b){

int product=0,temp=0,i=0;
  char result[10];
  product = a*b;
  temp = product;
  
  Serial.println(product);
  while(temp!=0){
    
    result[i] = temp%10+48;
    temp/=10;
    i++;
  }
  
  for(int j=i-1;j>=0;j--){
    writeLcd(result[j]);
    recieveData();
  }

    return;
  }
void quotient(int a,int  b){

int q=0,temp=0,i=0;
  char result[10];
  q = a/b;
  temp = q;
  
  Serial.println(q);
  while(temp!=0){
    
    result[i] = temp%10+48;
    temp/=10;
    i++;
  }
  
  for(int j=i-1;j>=0;j--){
    writeLcd(result[j]);
    recieveData();
  }

    return;
  }
  