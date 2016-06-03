#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, long delay)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _delay = delay;
  _lastButtonState = LOW;
  _lastDebounceTime = 0;
  _buttonState = LOW;
}

boolean Button::read()
{
 int reading = digitalRead(_pin);
  if (reading != _lastButtonState) {
    // reset the debouncing timer
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _delay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != _buttonState) {
      _buttonState = reading;
    }
  }
  return (_buttonState == HIGH);
}
