
int i=0;
int data;
void setup()
{
  DDRD=0b01110000;  // PD4-6
}

void loop()
{
  data=0b10101010;
  for(i=0;i<8;i++){
    
    digitalWrite(5, (data>>(7-i))&0x01 );  // Data Pin
        
    digitalWrite(6, HIGH);  // Clock Pin
  	delay(10);
  	digitalWrite(6, LOW);
  	delay(10);
  }

  digitalWrite(4, HIGH);   // Output Register Clock
  delay(10);
  digitalWrite(4, LOW);
  delay(10);
}