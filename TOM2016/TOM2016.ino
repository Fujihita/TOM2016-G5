#include <Motor.h> // include Motor control library
#include <Keypad.h>
#include <EEPROM.h>
#include "TOM2016.h"

void setup()
{
  Serial.begin(9600);  
//initialize starting values
  motor1.run(0);
  motor2.run(0);
  motor3.run(0);
  motor4.run(0);
  
  timer = millis();
}

void loop()
{
// get keys input
  if (keypad.getKeys())
    {
      char input[4] = "abc";
      int k = 0;       
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
          if(keypad.key[i].stateChanged){
              if ((keypad.key[i].kstate == PRESSED) || (keypad.key[i].kstate == HOLD)){
                  input[k] = keypad.key[i].kchar;
                  k++;
              }
          }
        }
      eventHandler(input);
    }

  taskManager();
}

bool comboMatch(char match[3], char key[3]) // RegEx("/[abc]/)
{
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    if ((key[i] == match[0]) || (key[i] == match[1]) || (key[i] == match[2]))
    count++; 
  }
  if (count == 3)
  return true;
  else
  return false;
}

void eventHandler(char input[4])
{
    char match[4] = "127";
    if(comboMatch(match,input)){
    
            Serial.println("127");
    }
    strcpy(match, "16c");
    if(comboMatch(match,input)){
            Serial.println("17");
    }
    strcpy(match, "1bc");
    if(comboMatch(match,input)){
            Serial.println("1");
            task = 1;
    }
    strcpy(match, "2bc");
    if(comboMatch(match,input)){
            Serial.println("2");
            task = 1;
    }
    strcpy(match, "3bc");
    if(comboMatch(match,input)){
            Serial.println("3");
    }
    strcpy(match, "4bc");
    if(comboMatch(match,input)){
            Serial.println("4");
    }
    strcpy(match, "5bc");
    if(comboMatch(match,input)){
            Serial.println("5");
    }
    strcpy(match, "6bc");
    if(comboMatch(match,input)){
            Serial.println("6");
    }
    strcpy(match, "7bc");
    if(comboMatch(match,input)){
            Serial.println("7");
    }
    strcpy(match, "8bc");
    if(comboMatch(match,input)){
            Serial.println("8");
    }
    strcpy(match, "9bc");
    if(comboMatch(match,input)){
            Serial.println("9");
    }
    strcpy(match, "0bc");
    if(comboMatch(match,input)){
            Serial.println("0");
    }
    strcpy(match, "*bc");
    if(comboMatch(match,input)){
            Serial.println("*");
    }
    strcpy(match, "#bc");
    if(comboMatch(match,input)){
            Serial.println("#");
    }  
}

void setLock(Motor motor)
{
  // function to lock a finger
}

void releaseLock(Motor motor)
{
  // function fo free a finger
}

void taskManager()
{
/*
EEPROM.update(0,highByte(yourInteger);
EEPROM.update(1,lowByte(yourInteger);

byte high = EEPROM.read(0);
byte low = EEPROM.read(1);
int myInteger=word(high,low);
*/ 
  switch(task){
    case 1: // Free finger(1)
    {
            releaseLock(motor1);
            setLock(motor2);
            setLock(motor3);
            setLock(motor4);
            break;
    }  
    case 2: // Free finger(2)
    {
            setLock(motor1);
            releaseLock(motor2);
            setLock(motor3);
            setLock(motor4);
            break;
    }
  }
}

