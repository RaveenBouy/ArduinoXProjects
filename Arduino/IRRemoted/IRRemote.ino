/*
 Name:		IRRemote.ino
 Created:	7/14/2018 10:22:53 PM
 Author:	RavianXReaver
*/

#include "IRremote/IRremote.h"

const int RECV_PIN = 11;
IRsend irSend;
decode_results results;
IRrecv irrecv(RECV_PIN);

void setup() 
{
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}


void loop() 
{
	if (irrecv.decode(&results)) 
	{
		for(int i = 0; i <3; i++)
		{
			irSend.sendPanasonic(0x00707030CF, 32);
			Serial.println("Sent");
			delay(40);
		}
		irrecv.resume(); // Receive the next value
	}
}
