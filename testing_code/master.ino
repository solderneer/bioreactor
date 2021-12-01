#include <Wire.h>
#define SLAVE_ADDR 9
#define I2C_SDA 21
#define I2C_SCL 22

void setup() {
 Wire.begin (I2C_SDA, I2C_SCL); // Configure the pins
 Serial.begin(9600); 
}

byte x = B101;

int  a;
int b;
int c;

int xs[8] = [];





void loop() {
  //Wire.beginTransmission(9); 
  //Wire.write(x);      
  //Wire.endTransmission();    // stop transmitting
  
  Wire.requestFrom(SLAVE_ADDR, 1);
  while (Wire.available()) { // slave may send less than requested
     xs += int(Wire.read());
     //b = int(Wire.read());
     //c = Wire.read();
  
  //char c = Wire.read(); 



  
  }
  Serial.println(a); 
  delay(500);
}
