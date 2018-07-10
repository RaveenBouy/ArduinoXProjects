/*
 Name:		LED.ino
 Created:	7/2/2018 6:49:25 PM
 Author:	RavianXReaver
*/

#include "stdio.h"

#define LEDPin1		14
#define SwitchPin1	15
#define LEDPin2		16
#define SwitchPin2	17
#define BuzzPin		18
#define potPin		4

int val = 0;

void setup() 
{
	pinMode(LEDPin1, OUTPUT);
	pinMode(SwitchPin1, INPUT);
	pinMode(LEDPin2, OUTPUT);
	pinMode(SwitchPin2, INPUT);
	pinMode(BuzzPin, OUTPUT);
}

void loop() 
{
	val = analogRead(potPin);
	if((digitalRead(SwitchPin1)==HIGH) || (digitalRead(SwitchPin2)==HIGH))
	{
		if(digitalRead(SwitchPin1)==HIGH)
		{
			digitalWrite(LEDPin1, HIGH);
			digitalWrite(BuzzPin, HIGH);
			//delay(val);
		}
		else
		{
			digitalWrite(LEDPin1, LOW);			
		}
		
		if(digitalRead(SwitchPin2)==HIGH)
		{
			digitalWrite(LEDPin2, HIGH);
			digitalWrite(BuzzPin, HIGH);
			//delay(val);
		}
		else
		{
			digitalWrite(LEDPin2, LOW);
		}	
	}
	else
	{
		digitalWrite(BuzzPin, LOW);
		digitalWrite(LEDPin1, LOW);
		digitalWrite(LEDPin2, LOW);
	}
		
	delay(val);
}
