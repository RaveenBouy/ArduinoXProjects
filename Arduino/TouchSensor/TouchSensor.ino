/*
 Name:		TouchSensor.ino
 Created:	7/19/2018 5:03:18 PM
 Author:	RavianXReaver
*/
#include "U8glib.h"

#define TSensorPin 14

U8GLIB_SH1106_128X64 OLED(5, 4, 3, 2);
int touch = 0;

void setup() 
{
	OLED.setRot180();
	pinMode(TSensorPin, 0);
	if (OLED.getMode() == U8G_MODE_R3G3B2)
	{
		OLED.setColorIndex(255);     // white
	}
	else
		if (OLED.getMode() == U8G_MODE_GRAY2BIT)
		{
			OLED.setColorIndex(3);         // max intensity
		}
		else
			if (OLED.getMode() == U8G_MODE_BW)
			{
				OLED.setColorIndex(1);         // pixel on
			}
			else
				if (OLED.getMode() == U8G_MODE_HICOLOR)
				{
					OLED.setHiColorByRGB(255, 255, 255);
				}
}

void Draw()
{
	OLED.setFont(u8g_font_04b_03br);
	OLED.setPrintPos(0, 20);
	OLED.print("Touch Sensor Example");
	OLED.setPrintPos(0, 40);
	OLED.print("Touch Detected");
}

void Draw2()
{
	OLED.setFont(u8g_font_04b_03br);
	OLED.setPrintPos(0, 20);
	OLED.print("Touch Sensor Example");
	OLED.setPrintPos(0, 40);
	OLED.print("");
}

void loop() 
{
	 OLED.firstPage();
	(digitalRead(TSensorPin) == 1) ? touch = 1 : touch = 0;

	if(touch == 1)
	{
		do  
		{	
			Draw();
		} 
		while(OLED.nextPage());
	}
	else
	{
		do  
		{	
			Draw2();
		} 
		while(OLED.nextPage());
	}
}
