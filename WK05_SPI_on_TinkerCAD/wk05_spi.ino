#include<SPI.h>

int CLK_PIN = 13;
int SS1_PIN  = 10;
int DS_PIN  = 11;
int SS2_PIN  = 9;

int map7seg[3] = {0x3F,0x06,0x5B};

void spi1_write(unsigned char cData){
  shiftOut(DS_PIN, CLK_PIN, MSBFIRST, cData);
  digitalWrite(SS1_PIN, HIGH);
  digitalWrite(SS1_PIN, LOW);
}
void spi2_write(unsigned char cData){
  shiftOut(DS_PIN, CLK_PIN, MSBFIRST, cData);
  digitalWrite(SS2_PIN, HIGH);
  digitalWrite(SS2_PIN, LOW);
}

void setup()
{
  pinMode(CLK_PIN, OUTPUT);
  pinMode(SS1_PIN, OUTPUT);
  pinMode(DS_PIN, OUTPUT);
}

void loop()
{	
  int num = 35;
  spi1_write(map7seg[1]);
  spi2_write(map7seg[1]);
  delay(500);
}
