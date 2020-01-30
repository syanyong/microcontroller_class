int i=0;
void setup()
{
  pinMode(13, OUTPUT);
  DDRB=0x00;
  DDRD=0x80;
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void loop()
{
  //PORTD=(PINB&0x01)<<7;
  /*PORTD=0x80;
  delay(100);
  PORTD=0x00;
  delay(100);*/
  
  if (i>15)
    i=0;
  
  PORTD=PORTD&0x00;
  if (i <= 7) {
  int data = 0x01<<i;
  for (int i=7; i >= 0; i--){
    PORTD|=((data>>i)&0x01)<<5;
  PORTD|=0x40;
    delay(10);
    PORTD&=0x00;
    delay(10);
  }
  PORTD=PORTD|0x10;
  }
  else{
  PORTD=PORTD&0x00;
  int data = 0x01<<(i-8);
  for (int i=7; i >= 0; i--){
    PORTD|=((data>>i)&0x01)<<5;
  PORTD|=0x40;
    delay(10);
    PORTD&=0x00;
    delay(10);
  }
  PORTD=PORTD|0x08;
  }
  delay(500);
  i+=1;
}
