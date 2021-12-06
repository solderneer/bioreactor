#include <Arduino.h>
#include <Wire.h>

#include "temp_controller.h"
#include "motor_controller.h"
#include "ph_controller.h"
#include "comm.h"
#include "pid.h"

// Pins for temperature subsystem
#define HEATER_PIN 11
#define THERMISTER_PIN A0

// Pins for pH subsystem
#define PH_PIN A1
#define ACID_PIN 6
#define ALKALI_PIN 10

// Pins for motor subsystem
#define MOTOR_PIN 5
#define ENCODER_PIN 3

// pH calibration voltages
#define PH_5 1.15 
#define PH_9 3.5
// pH maximum flow ms (should be less than sample time)
#define PH_MAX_MS 200

// Temperature calibration
#define TEMP_R_FIX 9850.0
#define TEMP_A1 6.627567593e-03
#define TEMP_A2 -7.21277582e-04
#define TEMP_A3 4.396579939e-06

// Default setpoints
#define DEFAULT_TEMP 30.0
#define DEFAULT_RPM 1000.0
#define DEFAULT_PH 5.0

// I2C ADDRESS
#define SLAVE_ADDR 9

// I2C Callbacks
void dataReceive(int numberBytes);
void dataRequest(void);

// Transmit buffer
byte t_buffer[24];
unsigned long last_time = 0;
  
MotorController mc(MOTOR_PIN, ENCODER_PIN);
TempController tc(HEATER_PIN, THERMISTER_PIN);
PhController pc(PH_PIN, ACID_PIN, ALKALI_PIN);

PIDSystem temp(&tc, 500);
PIDSystem motor(&mc, 500);
PIDSystem ph(&pc, 500);

void setup() {
  // Setting up the temp subsystem
  tc.calibrate(TEMP_R_FIX, TEMP_A1, TEMP_A2, TEMP_A3);
  temp.setParameters(20.0, 5.0, 0.0);
  temp.setLimits(0.0, 255.0);
  temp._setpoint = DEFAULT_TEMP;

  // Setting up the pH subsystem
  pc.calibrate(PH_5, PH_9);
  ph.setParameters(1.0, 1.0, 1.0);
  ph.setLimits(-PH_MAX_MS, PH_MAX_MS);
  ph._setpoint = DEFAULT_PH;

  // Setting up the motor subsystem
  motor.setParameters(1.0, 1.0, 1.0);
  motor.setLimits(0.0, 255.0);
  motor._setpoint = DEFAULT_RPM;
  
  // Setting up I2C communication
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(dataRequest);
  Wire.onReceive(dataReceive);

  Serial.begin(9600);
}

void loop() {
  temp.run();
  // ph.run();
  // TODO: Bug where motor rpm suddenly halfs randomly for no reason and there is random noise
  // motor.run();

  unsigned long now = millis();
  int time_change = now - last_time;

  mc.write(30);
  
  if(time_change >= 2000) {
    Serial.println("TEMP:");
    temp.print();
    Serial.println("PH:");
    ph.print();
    Serial.println("MOTOR:");
    motor.print();
    last_time = now;
  }
  /*
  double temp = tc.measureTemp();
  tc.setHeaterOutput(255);
  Serial.println("TEMP:");
  Serial.println(temp);
  delay(1000);
  */
}

void dataReceive(int numberBytes) {
  // Some sort of command
  byte command[5] = {0, 0, 0, 0, 0};
  int i = 0;

  // Read the command into the buffer
  while(Wire.available() && i < 5) {
    command[i] = Wire.read();
    i++;
  }

  // buffer[0] is command, buffer[1-4] is a float
  bool rw = command[0] >> 7; // 1 is write, 0 is read
  uint8_t subsystem_select = (uint8_t)((command[0] & (0b01100000)) >> 5);
  uint8_t value_select = (uint8_t)((command[0] & (0b00011000)) >> 3);
  double value = unloadFloat(command, 1);

  
  // Serial.println(command[0], HEX);
  // Serial.println(value_select);
  // Serial.println(value);*/

  if(rw == true) {
    // Write mode
    if(subsystem_select == 1) {
      // Temp subsystem
      switch(value_select) {
        case 0: temp._setpoint = value; break;
        case 1: temp.setKp(value); break;
        case 2: temp.setKi(value); break;
        case 3: temp.setKd(value); break;
        default: break;
      } 
    }
    else if(subsystem_select == 2) {
      // pH subsystem
      switch(value_select) {
        case 0: ph._setpoint = value; break;
        case 1: ph.setKp(value); break;
        case 2: ph.setKi(value); break;
        case 3: ph.setKd(value); break;
        default: break;
      } 
    } else if(subsystem_select == 3) {
      // Motor subsystem
      switch(value_select) {
        case 0: motor._setpoint = value; break;
        case 1: motor.setKp(value); break;
        case 2: motor.setKi(value); break;
        case 3: motor.setKd(value); break;
        default: break;
      } 
    }
  } else {
    // Read mode
    if(subsystem_select == 1) {
      // Temp subsystem log
      PIDLog log = temp.log();
      loadLogPacket(&log, t_buffer); 
    } else if(subsystem_select == 2) {
      // pH subsystem
      PIDLog log = ph.log();
      loadLogPacket(&log, t_buffer); 
    } else if(subsystem_select == 3) {
      // Motor subsystem
      PIDLog log = motor.log();
      loadLogPacket(&log, t_buffer); 
    }
  }
}

void dataRequest() {
  Wire.write(t_buffer, 24);
}
