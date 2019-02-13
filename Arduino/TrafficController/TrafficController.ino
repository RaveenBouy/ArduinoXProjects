/*
 Name:		TrafficController.ino
 Created:	2/12/2019 3:21:07 PM
 Author:	RavianXReaver
*/

#include "stdio.h"
#include "string.h"
#include <stddef.h>

//*****Lane1*****
//Sensor1
#define TRIG_PIN1			11
#define ECHO_PIN1			10
//Sensor2
#define TRIG_PIN2			9
#define ECHO_PIN2			8

#define LANE1_RED_LED		22
#define LANE1_ORANGE_LED	23	
#define LANE1_GREEN_LED		24

//*****Lane2*****
//Sensor3
#define TRIG_PIN3			7
#define ECHO_PIN3			6
//Sensor4
#define TRIG_PIN4			3
#define ECHO_PIN4			2

#define LANE2_RED_LED		46	
#define LANE2_ORANGE_LED	47
#define LANE2_GREEN_LED		48

int range = 15;
int timerMain, previouslane, cycles, lane1timer, lane2timer = 0;
long distance1, duration1, distance2, duration2, distance3, duration3, distance4, duration4 = 0;
bool sensor1, sensor2, sensor3, sensor4;

void setup() 
{
	Serial.begin(9600);
	pinMode(TRIG_PIN1, OUTPUT);
	pinMode(ECHO_PIN1, INPUT);
	pinMode(TRIG_PIN2, OUTPUT);
	pinMode(ECHO_PIN2, INPUT);
	pinMode(TRIG_PIN3, OUTPUT);
	pinMode(ECHO_PIN3, INPUT);
	pinMode(TRIG_PIN4, OUTPUT);
	pinMode(ECHO_PIN4, INPUT);
	pinMode(LANE1_RED_LED, OUTPUT);
	pinMode(LANE1_ORANGE_LED, OUTPUT);
	pinMode(LANE1_GREEN_LED, OUTPUT);
	pinMode(LANE2_RED_LED, OUTPUT);
	pinMode(LANE2_ORANGE_LED, OUTPUT);
	pinMode(LANE2_GREEN_LED, OUTPUT);
}

void Sensor1()
{
	digitalWrite(TRIG_PIN1, LOW); 
	delayMicroseconds(2); 
	digitalWrite(TRIG_PIN1, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG_PIN1, LOW); 
	duration1 = pulseIn(ECHO_PIN1, HIGH);

	//Calculate the distance (in cm) based on the speed of sound.
	distance1 = (duration1 * 0.0344)/2;
}

void Sensor2()
{
	digitalWrite(TRIG_PIN2, LOW); 
	delayMicroseconds(2); 
	digitalWrite(TRIG_PIN2, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG_PIN2, LOW); 
	duration2 = pulseIn(ECHO_PIN2, HIGH);

	//Calculate the distance (in cm) based on the speed of sound.
	distance2 = (duration2 * 0.0344)/2;
}

void Sensor3()
{
	digitalWrite(TRIG_PIN3, LOW); 
	delayMicroseconds(2); 
	digitalWrite(TRIG_PIN3, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG_PIN3, LOW); 
	duration3 = pulseIn(ECHO_PIN3, HIGH);

	//Calculate the distance (in cm) based on the speed of sound.
	distance3 = (duration3 * 0.0344)/2;
}

void Sensor4()
{
	digitalWrite(TRIG_PIN4, LOW); 
	delayMicroseconds(2); 
	digitalWrite(TRIG_PIN4, HIGH);
	delayMicroseconds(10); 
	digitalWrite(TRIG_PIN4, LOW); 
	duration4 = pulseIn(ECHO_PIN4, HIGH);

	//Calculate the distance (in cm) based on the speed of sound.
	distance4 = (duration4 * 0.0344)/2;
}

void Lane1()
{
	Sensor1();
	Sensor2();

	if(distance1 <= range && distance1 != 0)
	{
		sensor1 = true;
		Serial.println("Sensor1");
	}
	else
	{
		sensor1 = false;
	}

	if(distance2 <= range && distance2 != 0)
	{
		sensor2 = true;
		Serial.println("Sensor2");
	}
	else
	{
		sensor2 = false;
	}
}

void Lane2()
{
	Sensor3();
	Sensor4();

	if(distance3 <= range && distance3 != 0)
	{
		sensor3 = true;
		Serial.println("Sensor3");
	}
	else
	{
		sensor3 = false;
	}
	
	if(distance4 <= range && distance4 != 0)
	{
		sensor4 = true;
		Serial.println("Sensor4");
	}
	else
	{
		sensor4 = false;
	}
}

void Lane1Lights(int x)
{
	if (x == 1) //Start
	{
		digitalWrite(LANE1_RED_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE1_ORANGE_LED, HIGH);
		delayMicroseconds(1000);
		digitalWrite(LANE1_ORANGE_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE1_GREEN_LED, HIGH);
	}

	if (x == 2) //Stop
	{
		digitalWrite(LANE1_GREEN_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE1_ORANGE_LED, HIGH);
		delayMicroseconds(1000);
		digitalWrite(LANE1_ORANGE_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE1_RED_LED, HIGH);	
	}
}

void Lane2Lights(int x)
{
	if (x == 1) //Start
	{
		digitalWrite(LANE2_RED_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE2_ORANGE_LED, HIGH);
		delayMicroseconds(1000);
		digitalWrite(LANE2_ORANGE_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE2_GREEN_LED, HIGH);
	}

	if (x == 2) //Stop
	{
		digitalWrite(LANE2_GREEN_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE2_ORANGE_LED, HIGH);
		delayMicroseconds(1000);
		digitalWrite(LANE2_ORANGE_LED, LOW);
		delayMicroseconds(1000);
		digitalWrite(LANE2_RED_LED, HIGH);	
	}
}

void ResetTimerMain() 
{
	timerMain = 0;
}


void Algorithm()
{
	Lane1();
	Lane2();

	if(timerMain == 1 && cycles == 0)
	{
		Lane1Lights(1);
		Lane2Lights(2);
		previouslane = 1;
	}

	if (timerMain == 15 && cycles == 0)
	{
		Lane1Lights(2);
		Lane2Lights(1);
		previouslane = 2;
	}

	if (timerMain == 30)
	{
		++cycles;
	}

	if (cycles>0)
	{
		if (timerMain == 15 || timerMain == 30)
		{
			Serial.print("previouslane: ");
			Serial.print(previouslane);
			Serial.println();

			if (previouslane == 2)
			{
				if (sensor1 && sensor2)
				{
					lane1timer = 30;
				}
				else
				{
					lane1timer = 15;
				}

				previouslane = 1;

				if (lane1timer == 15)
				{
					Lane1Lights(1);
					Lane2Lights(2);

					if (timerMain == 15)
					{
						ResetTimerMain();
						return;
					}
				}

				if (lane1timer == 30)
				{
					ResetTimerMain();
					Lane1Lights(1);
					Lane2Lights(2);
				}
			}
			else
			{
				if (sensor3 && sensor4)
				{
					lane2timer = 30;
				}
				else
				{
					lane2timer = 15;
				}
				previouslane = 2;

				if (lane2timer == 15)
				{
					Lane1Lights(2);
					Lane2Lights(1);

					if (timerMain == 15)
					{
						ResetTimerMain();
						return;
					}
				}

				if (lane2timer == 30)
				{
					ResetTimerMain();
					Lane1Lights(2);
					Lane2Lights(1);
				}
			}
		}
	}
}

void loop() 
{
	timerMain++;
	Serial.println(timerMain);
	Algorithm();

	if(timerMain == 30)
	{
		timerMain = 0;
	}
	delay(1000);
}
