#include "Arduino.h"
#include "pid.h"

PIDSystem::PIDSystem(Controller *controller, int sample_time) {
  _controller = controller;
  _sample_time = sample_time;
}

void PIDSystem::run(void) {
  // Return if mode != AUTOMATIC
  if(!_mode) return;

  unsigned long now = millis();
  int time_change = now - _last_time;

  // If we've waited longer than the sample time
  if(time_change >= _sample_time) {
    
    // Get the input
    _input = _controller->read();

    // Compute all the error variables
    double error = _setpoint - _input;
    _iterm += (_ki * error);

    // Clamping the iterm to prevent windup
    if(_iterm > _out_max)
      _iterm = _out_max;
    else if(_iterm < _out_min)
      _iterm = _out_min;

    double d_input = _input - _last_input;

    // Compute PID output
    _output = _kp * error + _iterm - _kd * d_input;

    // Clamping the output to prevent windup
    if(_output > _out_max)
      _output = _out_max;
    else if(_output < _out_min)
      _output = _out_min;

    _controller->write(_output);

    // Remember some variables
    _last_input = _input;
    _last_time = now;
  }
}

void PIDSystem::setParameters(double kp, double ki, double kd) {
  double sample_time_secs = ((double)_sample_time)/1000;

  _kp = kp;
  _ki = ki * sample_time_secs;
  _kd = kd / sample_time_secs;
}

void PIDSystem::setKp(double kp) {
  _kp = kp;
}

void PIDSystem::setKi(double ki) {
  double sample_time_secs = ((double)_sample_time)/1000;
  _ki = ki * sample_time_secs;
}

void PIDSystem::setKd(double kd) {
  double sample_time_secs = ((double)_sample_time)/1000;
  _kd = kd / sample_time_secs;
}

void PIDSystem::setLimits(double out_min, double out_max) {
  _out_min = out_min;
  _out_max = out_max;
    
  // Clamping the iterm to prevent windup
  if(_iterm > _out_max)
    _iterm = _out_max;
  else if(_iterm < _out_min)
    _iterm = _out_min;

  // Clamping the output to prevent windup
  if(_output > _out_max)
    _output = _out_max;
  else if(_output < _out_min)
    _output = _out_min;
}

void PIDSystem::setMode(int mode) {
  _mode = mode;

  _last_input = _input;
  _iterm = _output;

  // Clamping the iterm to prevent windup
  if(_iterm > _out_max)
    _iterm = _out_max;
  else if(_iterm < _out_min)
    _iterm = _out_min;
}

PIDLog PIDSystem::log(void) {
  PIDLog log;
  double sample_time_secs = ((double)_sample_time)/1000;

  log.setpoint = _setpoint;
  log.input = _input;
  log.output = _output;
  log.kp = _kp;
  log.ki = _ki / sample_time_secs;
  log.kd = _kd * sample_time_secs;

  return log;
}

void PIDSystem::print(void) {
  PIDLog pid_log = log();

  Serial.print("Setpoint: ");
  Serial.println(pid_log.setpoint);
  Serial.print("Input: ");
  Serial.println(pid_log.input);
  Serial.print("Output: ");
  Serial.println(pid_log.output);
  Serial.print("Kp: ");
  Serial.println(pid_log.kp);
  Serial.print("Ki: ");
  Serial.println(pid_log.ki);
  Serial.print("Kd: ");
  Serial.println(pid_log.kd);
  Serial.println("----------------------");
}
