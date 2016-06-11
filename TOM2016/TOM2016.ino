#include <Motor.h> // include Motor control library
#include <Keypad.h>
#include <EEPROM.h>
#include <Finger.h>
#include "TOM2016.h"

void setup()
{
  //Serial.begin(9600);  
//initialize starting values
  timer = millis();
}

void loop()
{  
  finger1.run();
  finger2.run();
  finger3.run();
  finger4.run();
  
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
}

bool comboMatch(char match[3], char key[3]) // RegEx("/[abc]/")
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
    char match[4] = "1bc";
    if(comboMatch(match,input)){
            //Serial.println("1");
            finger1.unlock();
            finger2.lock();
            finger3.lock();
            finger4.lock();
    }
    strcpy(match, "2bc");
    if(comboMatch(match,input)){
            //Serial.println("2");
            finger1.lock();
            finger2.unlock();
            finger3.lock();
            finger4.lock();
    }
    strcpy(match, "3bc");
    if(comboMatch(match,input)){
            //Serial.println("3");
            finger1.lock();
            finger2.lock();
            finger3.unlock();
            finger4.lock();
    }
/*    strcpy(match, "4bc");
    if(comboMatch(match,input)){
            //Serial.println("4");
            finger1.lock();
            finger2.lock();
            finger3.lock();
            finger4.unlock();
    }
    strcpy(match, "5bc");
    if(comboMatch(match,input)){
           // Serial.println("5");
            finger1.unlock();
            finger2.unlock();
            finger3.unlock();
            finger4.unlock();
    }
    strcpy(match, "6bc");
    if(comboMatch(match,input)){
            //Serial.println("6"); 
    }*/
    strcpy(match, "0bc");
    if(comboMatch(match,input)){
            //Serial.println("0");
            finger1.lock();
            finger2.lock();
            finger3.lock();
            finger4.unlock();
    }
    strcpy(match, "*bc");
    if(comboMatch(match,input)){
            //Serial.println("*");
            finger1.unlock();        
            finger2.unlock();
            finger3.unlock();
            finger4.unlock();
    }
    strcpy(match, "#bc");
    if(comboMatch(match,input)){
            //Serial.println("#");
            finger1.reset();        
            finger2.reset();
            finger3.reset();
            finger4.reset();
    }  
}


/*
EEPROM.update(0,highByte(yourInteger);
EEPROM.update(1,lowByte(yourInteger);

byte high = EEPROM.read(0);
byte low = EEPROM.read(1);
int myInteger=word(high,low);
*/ 
