/*
 Name:		MH_Sensor.ino
 Created:	7/12/2018 5:51:00 PM
 Author:	RavianXReaver
*/
#include "stdio.h"

#define AOPin 1
#define DOPin 3

void setup() 
{
	Serial.begin(9600);
	pinMode(AOPin, 0);
	pinMode(DOPin, 0);
}

void loop() 
{
	Serial.print("Analog:");
	Serial.print(analogRead(AOPin));
	Serial.println("");
	Serial.print("Digital:");
	Serial.print(digitalRead(DOPin));
	Serial.println("");
	delay(400);
}
