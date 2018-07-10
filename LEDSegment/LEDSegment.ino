/*
 Name:		LEDSegment.ino
 Created:	7/5/2018 2:55:43 PM
 Author:	RavianXReaver
*/

#include "stdio.h"
#include "Metro/Metro.h"

/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

 */
 
// Pin 2-8 is connected to the 7 segments of the display.

#define DD			1
#define pinA		2
#define pinB		3
#define pinC		4
#define pinD		5
#define pinE		6
#define pinF		7
#define pinG		8
#define D1			9
#define D2			10
#define D3			11
#define D4			12
#define pinForward	14
#define pinBackward 15
#define	pinMins		16
#define pinSecs		17

int timerForward	= 0;
int timerBackward	= 0;
int second			= 0;	//4th Segment   displays seconds
int second2			= 0;	//3rd Segment   displays seconds
int minute			= 0;	//2nd Segment   displays Minutes
int minute2			= 0;	//1st Segment   displays Minutes
double time;
String tempVal1, tempVal2;
int tempSeconds;
int secondsCounter		= 0;
int secondsCounterTemp	= 0;
int secondsCounterTemp2 = 0;
int minutesCounterTemp	= 0;
int minutesCounterTemp2 = 0;
int seconds210thplace;
Metro delay1 = Metro(1000);
Metro delay2 = Metro(1);
Metro delay3 = Metro(1);

void setup() 
{               
	Serial.begin(9600);
	pinMode(DD, 1);
	pinMode(pinA, OUTPUT);     
	pinMode(pinB, OUTPUT);     
	pinMode(pinC, OUTPUT);     
	pinMode(pinD, OUTPUT);     
	pinMode(pinE, OUTPUT);     
	pinMode(pinF, OUTPUT);     
	pinMode(pinG, OUTPUT);   
	pinMode(D1, OUTPUT);  
	pinMode(D2, OUTPUT);  
	pinMode(D3, OUTPUT);  
	pinMode(D4, OUTPUT);  
	pinMode(pinForward, 0);
	pinMode(pinBackward, 0);
	pinMode(pinMins, 0);
	pinMode(pinSecs, 0);
}

void Segment1()  
{
	digitalWrite(D1, 0);
	digitalWrite(D2, 1);
	digitalWrite(D3, 1);
	digitalWrite(D4, 1);
}

void Segment2()
{
	digitalWrite(D1, 1);
	digitalWrite(D2, 0);
	digitalWrite(D3, 1);
	digitalWrite(D4, 1);
}

void Segment3()
{
	digitalWrite(D1, 1);
	digitalWrite(D2, 1);
	digitalWrite(D3, 0);
	digitalWrite(D4, 1);
}

void Segment4()
{
	digitalWrite(D1, 1);
	digitalWrite(D2, 1);
	digitalWrite(D3, 1);
	digitalWrite(D4, 0);
}

void SegmentsDismiss()
{
	digitalWrite(D1, 0);
	digitalWrite(D2, 0);
	digitalWrite(D3, 0);
	digitalWrite(D4, 0);
}

void Display0()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 1);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 0);
}

void Display1()
{
	digitalWrite(pinA, 0);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 0);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 0);
	digitalWrite(pinG, 0);
}

void Display2()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 0);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 1);
	digitalWrite(pinF, 0);
	digitalWrite(pinG, 1);
}

void Display3()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 0);
	digitalWrite(pinG, 1);
}

void Display4()
{
	digitalWrite(pinA, 0);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 0);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 1);
}

void Display5()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 0);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 1);
}

void Display6()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 0);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 1);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 1);
}

void Display7()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 0);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 0);
	digitalWrite(pinG, 0);
}

void Display8()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 1);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 1);
}

void Display9()
{
	digitalWrite(pinA, 1);
	digitalWrite(pinB, 1);
	digitalWrite(pinC, 1);
	digitalWrite(pinD, 1);
	digitalWrite(pinE, 0);
	digitalWrite(pinF, 1);
	digitalWrite(pinG, 1);
}

void Display0to9()  //First call the segment, then this method.
{
	Display0();
	delay(1000);
	Display1();
	delay(1000);
	Display2();
	delay(1000);
	Display3();
	delay(1000);
	Display4();
	delay(1000);
	Display5();
	delay(1000);
	Display6();
	delay(1000);
	Display7();
	delay(1000);
	Display8();
	delay(1000);
	Display9();
	delay(1000);
}

//Above are the major functions.
// Time max = 1 Hr Therefore the format is MM:SS

int falseX = 1;

void loop() 
{
	if((timerForward || timerBackward) == 0)
	{
		//Seconds Button
		if(digitalRead(pinSecs)==1)
		{
			++second;
			delay(300);
		}

		if (second == 10)
		{
			++second2;
		}

		if (second == 10)
		{
			second = 0;
		}

		if (second2 == 6)
		{
			second2 = 0;
		}

		SetSecond(second);
		delay(8);
		SetSecond2(second2);
		delay(8);

		//Minutes Button
		if(digitalRead(pinMins)==1)
		{
			++minute;
			delay(300);
		}

		if (minute == 10)
		{
			++minute2;
		}

		if (minute == 10)
		{
			minute = 0;
		}

		if (minute2 == 6)
		{
			minute2 = 0;
		}

		//digitalWrite(DD, 1);
		SetMinute(minute);
		delay(5);
		SetMinute2(minute2);
		delay(5);
	}
	
	if(digitalRead(pinForward) == 1)	//Forward Timer Button
	{
		ClearVars();
		SegmentsDismiss();

		tempVal1.concat(minute2);
		tempVal1.concat(minute);
		tempVal2.concat(second2);
		tempVal2.concat(second);

		tempSeconds = (strtol(stringToCharArray(tempVal1),NULL, 32)* 60) + strtol(stringToCharArray(tempVal2), NULL,0);
		Serial.println(tempSeconds);

		seconds210thplace = tempSeconds / 10;


		timerForward	= 1;
		timerBackward	= 0;
		TimerForward();
	}
	else
	if(digitalRead(pinBackward) == 1) 	//Backward Timer Button
	{
		ClearVars();
		timerForward	= 0;
		timerBackward	= 1;
		Serial.println(minute);
	}

	if(timerForward == 1)
	{
		Serial.print("secondsCounterTemp : ");
		Serial.print(secondsCounterTemp);
		Serial.println(" ");
		Serial.print("secondsCounterTemp2 : ");
		Serial.print(secondsCounterTemp2);
		Serial.println(" ");
		testFunc(secondsCounterTemp, secondsCounterTemp2, minutesCounterTemp, minutesCounterTemp2);
		TimerForward();
	}	
}

//Below are the custom methods

void ClearVars()
{
	tempVal1 = ""; 
	tempVal2 = "";
	tempSeconds = secondsCounter = secondsCounterTemp = secondsCounterTemp2 = seconds210thplace = minutesCounterTemp = minutesCounterTemp2 = 0;
}

char* stringToCharArray(String text)
{	
	char* buf = (char*) malloc(sizeof(char)*text.length()+1);
	text.toCharArray(buf, text.length()+1);
	return buf;
	free(buf);
}

void TimerForward()
{
	TimerForwardCounter();
}


void TimerForwardCounter()
{
	if (secondsCounter >= tempSeconds) timerForward = 0;

	

	while(secondsCounter<tempSeconds)
	{
		++secondsCounterTemp;
		++secondsCounter;

		if (secondsCounterTemp == 10)
		{
			secondsCounterTemp = 0;
			secondsCounterTemp2 +=1;
		}

		if(secondsCounterTemp2 == 6)
		{
			secondsCounterTemp2 = 0;
			minutesCounterTemp +=1;
		}

		if(minutesCounterTemp == 10)
		{
			minutesCounterTemp = 0;
			minutesCounterTemp2 +=1;
		}

		if(minutesCounterTemp2 == 6)
		{
			minutesCounterTemp2 = 0;
		}

		break;	
	}
	delay(1000);
}

void testFunc(int secondsCounterTemp, int secondsCounterTemp2, int minutesCounterTemp, int minutesCounterTemp2)
{
		SetSecond(secondsCounterTemp);
		delay(10);
		SetSecond2(secondsCounterTemp2);
		delay(10);
		SetMinute(minutesCounterTemp);
		delay(10);
		SetMinute2(minutesCounterTemp2);
		delay(10);
}

void SetSecond(int second)
{
	switch (second)
	{
		case 0: Segment4();
				Display0();
				
				break;
		case 1: Segment4();
				Display1();
				
		break;
		case 2: Segment4();
				Display2();
			
		break;
		case 3: Segment4();
				Display3();

		break;
		case 4: Segment4();
				Display4();

		break;
		case 5: Segment4();
				Display5();

		break;
		case 6: Segment4();
				Display6();

		break;
		case 7: Segment4();
				Display7();

		break;
		case 8: Segment4();
				Display8();

		break;
		case 9: Segment4();
				Display9();

		break;
	}

}

void SetSecond2(int second2)
{
	switch (second2)
	{
		case 0: Segment3();
				Display0();

				break;
		case 1: Segment3();
				Display1();

		break;
		case 2: Segment3();
				Display2();

		break;
		case 3: Segment3();
				Display3();

		break;
		case 4: Segment3();
				Display4();

		break;
		case 5: Segment3();
				Display5();

		break;
	}
}

void SetMinute(int minute)
{
	switch (minute)
	{
		case 0: Segment2();
				Display0();
				
				break;
		case 1: Segment2();
				Display1();
				
		break;
		case 2: Segment2();
				Display2();
			
		break;
		case 3: Segment2();
				Display3();

		break;
		case 4: Segment2();
				Display4();

		break;
		case 5: Segment2();
				Display5();

		break;
		case 6: Segment2();
				Display6();

		break;
		case 7: Segment2();
				Display7();

		break;
		case 8: Segment2();
				Display8();

		break;
		case 9: Segment2();
				Display9();

		break;
	}

}

void SetMinute2(int minute2)
{
	switch (minute2)
	{
		case 0: Segment1();
				Display0();

				break;
		case 1: Segment1();
				Display1();

		break;
		case 2: Segment1();
				Display2();

		break;
		case 3: Segment1();
				Display3();

		break;
		case 4: Segment1();
				Display4();

		break;
		case 5: Segment1();
				Display5();

		break;
	}
}

//Failed Attempt.