#ifndef TEMP_CONTROLLER_H
  #define TEMP_CONTROLLER_H
  
  #include "pid.h"

  class TempController : public Controller {
    public: 
      TempController(int heater_pin, int thermister_pin);
      double read();
      void write(double ouput);
      void setHeaterOutput(int output);
      int measureTemp(void);
      
    private:
      int _heater_pin = 9;
      int _thermister_pin = 10;
  };
#endif
