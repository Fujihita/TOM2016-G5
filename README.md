# TOM2016-G5 Project Touch Up
Tikkun Olam Makers 2016 event, team 5 project.

Description: A robotic glove/hand to aid a child who cannot control his hand and fingers properly.

TOM page: http://projects.tomglobal.org/project/144

This project uses a custom motor driver and finger driver libraries, along with Keypad library from Arduino playground. These libraries must be copied to \Arduino\libraries folder in order for the source file to compile properly. The hardware is assumed to have no sensor whatsoever that can determine the finger's current position/form. Finger tracking is done by software using timers and presets; such an operation is prone to accumulating errors and requires the starting position to be calibrated manually. It is, therefore, necessary to reset finger positions before powering down.

The exposed Finger library contains the following api

  // Constructor
  Finger(int SpeedPin, int DirectionPin);
    i.e: Declare a Finger object that uses the motor connected to pin 10 and 11
      Finger myFinger(10, 11);
  
  // Finger lock: stop the finger at the current position
  myFinger.lock();
  
  // Finger unlock: closing or opening the finger (go to either extremes and then stop there)
  myFinger.unlock();
  
  // Finger reset: return to the finger's starting position
  myFinger.reset();

Additionally there are two property functions

  // Modify time-out preset: the amount of time in seconds it takes to go from one extreme to another, this varies from
  // one motor and one finger to another
  myFinger.timeout(unsigned long timeout);
  
  // Periodic finger update function that needs to be placed in Arduino sketch's void loop() function
  // This is necessary to update all fingers' statuses every program cycle
  // ergo, passing the clock time from main program to encapsulated objects in order to emulate parallelism.
  myFinger.run();
  
