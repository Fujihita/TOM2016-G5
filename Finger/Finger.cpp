#include "Arduino.h"
#include "Motor.h"
#include "Finger.h"
#define	SPEED	150

Finger::Finger(int spPin, int dirPin) : _motor(spPin, dirPin)
{
  _motor.base(255);
  _timeout = 3000; //3 secs
  _dir = true;
  _status = 0;
  _offset = 0;
  
  _timer = millis();	
  lock();
}

void Finger::timeout(unsigned long timeout){
    _timeout = timeout;    
}

void Finger::lock(){
//_motor.run(0);
	_setLock();
	_status = 0;
}

void Finger::reset(){
	_status = 1;
	// start motor in reverse direction
	if (_dir)
	{
		_dir = false;
		_offset = _timeout - _offset; 	// inverse offset progress
	}
	_motor.run(-SPEED);
}

void Finger::unlock(){
//_motor.run(SPEED);
	if (_dir)
	{
		_motor.run(SPEED);
	}
	else
	{
		_motor.run(-SPEED);
	}
	_status = 2;
}

void Finger::run(){	
	switch(_status)
	{
		case 1:
		{
			_backToStart();
			break;
		}
		case 2:
		{
			_releaseLock();
			break;
		}
	}
	_timer = millis();
}

// Private functions

void Finger::_setLock()
{
   // function to lock a finger in place
   _motor.run(0);
}

void Finger::_releaseLock()
{
	_offset = _offset + (millis() - _timer);
  	// function fo free a finger
	if (_offset > _timeout)
	{
		_motor.run(SPEED);
		_dir = !_dir;
		_offset = 0;
		if (_dir)
		{
			_motor.run(SPEED);
		}
		else
		{
			_motor.run(-SPEED);
		}
		lock();
	}
}

void Finger::_backToStart()
{
	_offset = _offset + (millis() - _timer);
  	// function fo reset a finger
  	if (_offset > _timeout)
	{
		_dir = true;
		_offset = 0;
		lock();
	}
}