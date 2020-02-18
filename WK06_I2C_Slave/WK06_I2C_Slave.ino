#include <Wire.h>

#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10

int map7seg[10] = {
 0x3F,0x06, 0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

void spi_write_1(unsigned char cData) {
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);
}


void setup() {
  Wire.begin(0b0000001);
  
  // Register a function to be called 
  // when a master requests data from this slave device.
  Wire.onRequest(requestEvent);
  
  // Registers a function to be called 
  // when a slave device receives a transmission from a master.
  Wire.onReceive(receiveEvent);
  
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  Serial.begin(9600);           
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  int x = Wire.read();    
  spi_write_1(map7seg[x]);
}
void requestEvent() {
  Wire.write("ok!\n");   
}