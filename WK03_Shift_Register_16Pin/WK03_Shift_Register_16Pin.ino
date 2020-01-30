#define DATA_PIN    5
#define CLOCK_PIN   6
#define LATCH_PIN_1 4
#define LATCH_PIN_2 3

int i=0;
int data;

void setup()
{
  DDRD=0b01110000;  // PD4-6
}

void loop()
{
  data=0b1000000000000001;
  
  // Send 0-7 bits
  for(i=0;i<8;i++){
    
    digitalWrite(5, (data>>(7-i))&0x01 );  // Data Pin
        
    digitalWrite(6, HIGH);  // Clock Pin
    delay(10);
    digitalWrite(6, LOW);
    delay(10);
  }

  digitalWrite(LATCH_PIN_1, HIGH);   // Output Register Clock
  delay(10);
  digitalWrite(LATCH_PIN_1, LOW);
  delay(10);
  
  // Send 8-16 bits
  data = data>>8;
  for(i=0;i<8;i++){
    
    digitalWrite(5, (data>>(7-i))&0x01 );  // Data Pin
        
    digitalWrite(6, HIGH);  // Clock Pin
    delay(10);
    digitalWrite(6, LOW);
    delay(10);
  }

  digitalWrite(LATCH_PIN_2, HIGH);   // Output Register Clock
  delay(10);
  digitalWrite(LATCH_PIN_2, LOW);
  delay(10);
  
}
