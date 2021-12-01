#include <Wire.h>
#define SLAVE_ADDR 9
#define I2C_SDA 21
#define I2C_SCL 22

void setup() {
 Wire.begin (I2C_SDA, I2C_SCL); // Configure the pins
 Serial.begin(9600); 
}


float floatVal = 3.14;
byte *b = (byte *)&floatVal;

byte x[5]= {0B01000000, b[0], b[1], b[2], b[3]};
int  a;


void send_command(){
  Wire.beginTransmission(9);
  Wire.write(x, 5);
  Wire.endTransmission();    
  

}




void loop() {
  send_command();
  Serial.println(x[0]);
  Serial.println(b[0]);
  Serial.println(b[1]);
  Serial.println(b[2]);
  //Wire.beginTransmission(9); 
  //Wire.write(x);      
  //Wire.endTransmission();    // stop transmitting
  String received_string = "";
//  Wire.requestFrom(SLAVE_ADDR, 32);
//  float b;
//  while (Wire.available()) { // slave may send less than requested
//     char c = Wire.read();
//     received_string += c;
//     //float b = Wire.read();  
//  }
//  //Serial.println(received_string); 
//  Serial.println(b);
  delay(500);
}
