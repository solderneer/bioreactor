// Wire Slave Sender

#define SLAVE_ADDR 9  
#include <Wire.h>


void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600); 
}


byte x = B10;
byte y = B1010;
byte z = B1011;

int a;

void loop() {
 delay(100);
}



void requestEvent() {
  //Wire.write(x);
  Wire.write(y);
  //Wire.write(z);
}


void receiveEvent(int howMany)
{
  while(0 < Wire.available()) // loop through all but the last
  {
    a = Wire.read(); // receive byte as a character
    Serial.print(a);         // print the character
  }
}
