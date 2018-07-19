/*
 Name:		IRLaser.ino
 Created:	7/14/2018 11:13:39 PM
 Author:	RavianXReaver
*/
#include "IRremote/IRremote.h"

#define RECV_PIN  2
#define LaserPin  4

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  pinMode(LaserPin, 1);
  irrecv.enableIRIn();
  delay(500);
}

void loop() 
{
  if (irrecv.decode(&results))
  {
	Serial.println(results.value, HEX);

	switch (results.value)
	{
		case 0xFFA25D:	digitalWrite(LaserPin, 1);
						delay(500);
						digitalWrite(LaserPin, 0);
		break;
		case 0xFF629D:  digitalWrite(LaserPin, 1);
						delay(500);
						digitalWrite(LaserPin, 0);
						delay(500);
						digitalWrite(LaserPin, 1);
						delay(500);
						digitalWrite(LaserPin, 0);
		break;
		case 0xFF9867:  digitalWrite(LaserPin, 1);
		break;
		default : digitalWrite(LaserPin, 0);
		break;
	}
	irrecv.resume();
  }
}
