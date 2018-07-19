/*
 Name:		IRRemote.ino
 Created:	7/14/2018 10:22:53 PM
 Author:	RavianXReaver
*/

#include "IRremote/IRremote.h"

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}


void loop() 
{
  if (irrecv.decode(&results))
  {
        Serial.println(results.value, HEX);
		delay(500);
        irrecv.resume();
  }
}
