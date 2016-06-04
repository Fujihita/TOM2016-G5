#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
  Motor(int spPin, int dirPin);
  void base(int base);
  void run(int sp);

  private:
  int _base;
  int _spPin;
  int _dirPin;  
};

#endif