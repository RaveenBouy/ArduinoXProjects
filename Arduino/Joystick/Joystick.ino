/*
 Name:		Joystick.ino
 Created:	7/19/2018 7:26:54 PM
 Author:	RavianXReaver
*/

#include "u8glib.h"

#define XAxisPin 4
#define YAxisPin 5
#define MidButtonPin 17

U8GLIB_SH1106_128X64 OLED(5, 4, 3, 2);

void setup() 
{
	OLED.setRot180();
	pinMode(MidButtonPin, 0);
}

void Draw(int x, int y)
{
	OLED.setFont(u8g_font_6x10);
	OLED.setPrintPos(0, 20);
	OLED.print(x);
	OLED.setPrintPos(60, 20);
	OLED.print(y);
}

int x = 0;
int y = 0;

void loop() 
{
	OLED.firstPage();
	x = analogRead(XAxisPin);
	y = analogRead(YAxisPin);

	do  
	{	
		Draw(x,y);
	} 
	while(OLED.nextPage());
	delay(100);
}
