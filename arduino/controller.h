#ifndef CONTROLLER_H
  #define CONTROLLER_H
  // Abstract class for all subsystem controllers
  class Controller {
    public:
      virtual double read() = 0;
      virtual void write(double output) = 0;
  };
#endif
