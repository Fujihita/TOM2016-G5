#ifndef Finger_h
#define Finger_h

#include "Arduino.h"
#include "Motor.h"

class Finger
{
  public:
  Finger(int spPin, int dirPin);
  void lock(); // initial -> lock, reset -> lock
  void unlock(); // releaseLock
  void reset(); // setLock
  void timeout(unsigned long timeout);
  void run(); 
 
  private:
  Motor _motor;
  unsigned int _timeout;
  long _timer;
  long _offset;
  bool _dir;
  int _status; // resetting = 0, locking = 1, unlocking = 2
  void _setLock();
  void _releaseLock();
  void _backToStart();
};

#endif