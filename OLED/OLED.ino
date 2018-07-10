/*
    Name	:   OLED.ino
    Created	:	5/26/2018 1:51:48 PM
    Author	:   RAVIANXREAVER\RavianXReaver
*/

#include "U8glib.h"
#include "string.h"

U8GLIB_SH1106_128X64 triangle(5, 4, 3, 2);  

//int drawx = 0;

int triangleLoop = 0;


void draw(int x1,int x2,int x3,int y1,int y2,int y3) 
{ 
	triangle.setFont(u8g_font_unifont);
	triangle.setPrintPos(0, 64);
	triangle.print(triangleLoop);
	triangle.drawTriangle(x1, y1, x2, y2, x3, y3);
}

void setup(void) 
{
	Serial.begin(9600);
	triangle.setRot180();
	// set SPI backup if required
	//u8g.setHardwareBackup(u8g_backup_avr_spi);
	// assign default color value
	if (triangle.getMode() == U8G_MODE_R3G3B2) 
	{
	triangle.setColorIndex(255);     // white
	}
	else 
		if (triangle.getMode() == U8G_MODE_GRAY2BIT) 
		{
		triangle.setColorIndex(3);         // max intensity
		}
		else 
			if (triangle.getMode() == U8G_MODE_BW) 
			{
			triangle.setColorIndex(1);         // pixel on
			}
			else 
				if (triangle.getMode() == U8G_MODE_HICOLOR) 
				{
				triangle.setHiColorByRGB(255, 255, 255);
				}
}


void loop(void) 
{
	triangle.firstPage();

		do  
		{	
			if(triangleLoop%4==0)
			{	
				draw(40,60,80,20,60,20);
			}
			else
				if(triangleLoop%4==1)
				{
					draw(80,40,80,20,40,60);
				}		
				else
					if(triangleLoop%4==2)
					{	
						draw(60,40,80,20,60,60);
					}
					else
						if(triangleLoop%4==3)
						{
							draw(40,80,40,60,40,20);
						}		
		} 
		while(triangle.nextPage());

		triangleLoop++;
	
	delay(100);
}