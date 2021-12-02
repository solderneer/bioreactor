#include <Wire.h>

#define SLAVE_ADDR 9
#define I2C_SDA 21
#define I2C_SCL 22

// Union datatype for processing doubles
union float_buf { float f; byte b[4]; };
typedef struct {
  double setpoint;
  double input;
  double output;
  double kp;
  double ki;
  double kd;
} PIDLog;

// UTILITY FUNCTIONS

// Receive the log packet into a PIDLog struct
int receiveLogPacket(PIDLog* log);

// Unload the log packet from some byte buffer
PIDLog unloadLogPacket(byte* buffer);

// Unload a float from a buffer at some offset
double unloadFloat(byte* buffer, int offset);

// Load a float into a buffer at some offset
void loadFloat(double f, byte* buffer, int offset);

// rw: 0->read, 1->write
// subsystem: 0->nothing, 1->temp, 2->ph, 3->motor
// value: 0->setpoint, 1->kp, 2->ki, 3->kd
void sendCommandPacket(bool rw, uint8_t subsystem, uint8_t value_type, double value);

void setup() {
  // put your setup code here, to run once:
  Wire.begin(I2C_SDA, I2C_SCL); // Configure the pins
  Serial.begin(9600);
  sendCommandPacket(1, 2, 0, 10.0);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Set the Kp for temperature to 1

  // Request the temp subsystem data
  sendCommandPacket(0, 2, 0, 0.0);
  // Receive the temp subsystem data
  PIDLog out; 
  int stat = receiveLogPacket(&out);

  Serial.println(stat);
  Serial.println(out.setpoint);
  Serial.println(out.input);
  Serial.println(out.output);
  Serial.println(out.kp);
  Serial.println(out.ki);
  Serial.println(out.kd);
  Serial.println("------------------");

  delay(2000);
}


/************* UTILITY FUNCTIONS *******************/

void sendCommandPacket(bool rw, uint8_t subsystem, uint8_t value_type, double value) {
  byte command[5];
  command[0] |= (rw << 7);
  command[0] |= (subsystem & 0b00000011) << 5;
  command[0] |= (value_type & 0b00000011) << 3;
  loadFloat(value, command, 1);

  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(command, 5);
  Wire.endTransmission();
}

double unloadFloat(byte* buffer, int offset) {
  int i;
  union float_buf data;

  for(i = 0; i < 4; i++) {
    data.b[i] = buffer[i + offset];
  }

  return (double)data.f;
}

int receiveLogPacket(PIDLog* log) {
  byte buf[24];
  int i = 0;

  uint16_t received = 0;
  Wire.requestFrom(SLAVE_ADDR, 24);
  delay(100);
  while(Wire.available()) {
    buf[received] = Wire.read();
    received++;
  }

  if(received != 24)
    return -1;
  
  log->setpoint = unloadFloat(buf, 0);
  log->input = unloadFloat(buf, 4);
  log->output = unloadFloat(buf, 8);
  log->kp = unloadFloat(buf, 12);
  log->ki = unloadFloat(buf, 16);
  log->kd = unloadFloat(buf, 20);

  return 0;
}

void loadFloat(double f, byte* buffer, int offset) {
  int i;
  union float_buf data;
  data.f = (float)f;

  for(i = 0; i < 4; i++) {
    buffer[i + offset] = data.b[i];
  }
}

// Takes the log packet and populates the transmit buffer
void loadLogPacket(PIDLog* log, byte* buffer) {
  loadFloat(log->setpoint, buffer, 0); 
  loadFloat(log->input, buffer, 4); 
  loadFloat(log->output, buffer, 8);  
  loadFloat(log->kp, buffer, 12);
  loadFloat(log->ki, buffer, 16);
  loadFloat(log->kd, buffer, 20);
}
