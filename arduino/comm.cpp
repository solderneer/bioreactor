#include <Arduino.h>
#include "comm.h"
#include "pid.h"

double unloadFloat(byte* buffer, int offset) {
  int i;
  union float_buf data;

  for(i = 0; i < 4; i++) {
    data.b[i] = buffer[i + offset];
  }

  return (double)data.f;
}

PIDLog unloadLogPacket(byte* buffer) {
  PIDLog log;
  log.setpoint = unloadFloat(buffer, 0);
  log.input = unloadFloat(buffer, 4);
  log.output = unloadFloat(buffer, 8);
  log.kp = unloadFloat(buffer, 12);
  log.ki = unloadFloat(buffer, 16);
  log.kd = unloadFloat(buffer, 20);

  return log;
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
