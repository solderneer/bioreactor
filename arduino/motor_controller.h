#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "pid.h"

class MotorController : public Controller {
  public:
    MotorController(int motor_pin, int encoder_pin);
    double read();
    void write(double output);
    double measureSpeed(uint32_t timeout); // Timeout in milliseconds
    void setMotorOutput(int output);
    void setThreshold(int v);

  private:
    int _motor_pin;
    int _encoder_pin;
    int _threshold = 368;
};

#endif
