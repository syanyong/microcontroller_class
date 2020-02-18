#include <Wire.h>

int i = 0;

void setup() {
  //Initiate the Wire library and join 
  // the I2C bus as a master or slave. 
  // This should normally be called only once.
  Wire.begin();
  Serial.begin(9600); 
}

void loop() {
  // Begin a transmission to the I2C slave device 
  // with the given address 
  Wire.beginTransmission(0b0000001);
  
  // Writes data from master to slave
  Wire.write(i++);  
  
  // Ends a transmission0b0000001
  Wire.endTransmission();   
  
  if( i > 9) {
  	i = 0;
  }
     
  delay(500);
  
  // Used by the master to request bytes from a slave device.
  //Wire.requestFrom(1, 4);
  //while (Wire.available()) {
  //  char c = Wire.read(); 
  //  Serial.print(c);        
  //}    
  //x++;
  //if(x==6)x=0;  
}

