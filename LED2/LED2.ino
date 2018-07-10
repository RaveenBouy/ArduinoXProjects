/*
 Name:		LED2.ino
 Created:	7/9/2018 2:51:32 PM
 Author:	RavianXReaver

 Consists 12 LEDS startingfrom pin 1 - 12
 Change the LEDX.h file according to your requirement
*/
#include "stdio.h"
#include "LEDX.h"

int potVal = 0;

void setup() 
{
	pinMode(pinLED1, 1);
	pinMode(pinLED2, 1);
	pinMode(pinLED3, 1);
	pinMode(pinLED4, 1);
	pinMode(pinLED5, 1);
	pinMode(pinLED6, 1);
	pinMode(pinLED7, 1);
	pinMode(pinLED8, 1);
	pinMode(pinLED9, 1);
	pinMode(pinLED10, 1);
	pinMode(pinLED11, 1);
	pinMode(pinLED12, 1);
}

void loop() 
{
	Program3();
}
