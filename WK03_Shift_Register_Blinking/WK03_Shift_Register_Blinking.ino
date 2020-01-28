
#define Button1 !(PINB&0x01)
#define Button2 !(PINB&0x02)

int led_no=0;
int toggle=0;
int i = 0;

void set_shift_register(char data8) {
  PORTD=PORTD&0x00;
  for (int i=7; i >= 0; i--){
    PORTD|=((data8>>i)&0x01)<<5;
	PORTD|=0x40; // Shift Register Clock
    delay(1);
    PORTD&=0x00; 
    delay(1);
  }
  
  PORTD=PORTD|0x10; // Latch Pin (Output Register Clock)
  delay(1);
}

void setup()
{
  DDRB=0x00;
  DDRD=0x70;  // PD4-6
  Serial.begin(9600);
}

void loop()
{
  set_shift_register(0x01);

  if(Button1){
  	while(Button1);
    if (led_no >= 7)
      led_no=0;
    else
      led_no++;
  }
  if(Button2){
  	while(Button2);
    if (led_no <= 0)
      led_no=7;
    else
      led_no--;
  }
  if(toggle){
  	set_shift_register((0b1<<led_no));
  } else {
  	set_shift_register((0x00));
  }
  if (i>10){
	toggle = !toggle;
  	i=0;
  }
  delay(5);
  i+=1;
}