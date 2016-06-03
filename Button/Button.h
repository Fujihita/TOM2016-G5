#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
  Button(int pin, long delay);
  boolean read();
  
  private:
  int _pin; 
  int _buttonState;
  int _lastButtonState;
  long _delay;
  long _lastDebounceTime;
};

#endif