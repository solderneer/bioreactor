#include "Arduino.h"

#include "temp_controller.h"
#include "motor_controller.h"
#include "ph_controller.h"
#include "pid.h"

// Pins for temperature subsystem
#define HEATER_PIN 10
#define THERMISTER_PIN A0

// Pins for pH subsystem
#define PH_PIN A1
#define ACID_PIN 5
#define ALKALI_PIN 6

// Pins for motor subsystem
#define MOTOR_PIN 11
#define ENCODER_PIN 3

// pH calibration voltages
#define PH_5 1.15 
#define PH_9 3.5
// pH maximum flow ms (should be less than sample time)
#define PH_MAX_MS 200

// Temperature calibration
#define TEMP_R_FIX 10000.0
#define TEMP_A1 1.009249522e-03
#define TEMP_A2 2.378405444e-04
#define TEMP_A3 2.019202697e-07

// Default setpoints
#define DEFAULT_TEMP 30
#define DEFAULT_RPM 1000
#define DEFAULT_PH 5

const int log_time = 1000;
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
  temp.setParameters(1.0, 1.0, 1.0);
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
  
  Serial.begin(9600);
}

void loop() {
  temp.run();

  unsigned long now = millis();
  int time_change = now - last_time;

  if(time_change >= log_time) {
    temp.print();
    last_time = now;
  }
}
