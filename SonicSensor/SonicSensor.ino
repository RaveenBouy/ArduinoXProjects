#include "U8glib.h"

#define echoPin 10 // Echo Pin
#define trigPin 9 // Trigger Pin
#define mos 5
#define res 4
#define dc  3
#define cs  2
#define buzzPin 22
#define obstaclePin 11
#define reset 12

U8GLIB_SH1106_128X64 oled(mos,res,dc,cs);  

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration = 0, distance = 0; // Duration used to calculate distance
int obstacle = HIGH;

void draw(int distance) 
{ 
  oled.setFont(u8g_font_unifont);
  oled.setPrintPos(0, 20);
  oled.print("Distance: ");
  oled.setPrintPos(80, 20);
  oled.print(distance);
}

void draw2()
{ 
  oled.setFont(u8g_font_04b_03r);
  oled.setPrintPos(0, 30);
  oled.print("INTRUDER DETECTED!");
}

void draw3(String result)
{ 
  oled.setFont(u8g_font_04b_03b);
  oled.setPrintPos(0, 50);
  oled.print(result);
}

void setup() 
{
	//Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(buzzPin, OUTPUT);
	pinMode(obstaclePin, INPUT);
	pinMode(reset, OUTPUT);
	oled.setRot180();

	if (oled.getMode() == U8G_MODE_R3G3B2) 
	{
		oled.setColorIndex(255);     // white
	}
	else 
		if (oled.getMode() == U8G_MODE_GRAY2BIT) 
		{
			oled.setColorIndex(3);         // max intensity
		}
		else 
			if (oled.getMode() == U8G_MODE_BW) 
			{
				oled.setColorIndex(1);         // pixel on
			}
			else 
				if (oled.getMode() == U8G_MODE_HICOLOR) 
				{
					oled.setHiColorByRGB(255, 255, 255);
				}

}

void loop() 
{
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
	 oled.firstPage();
	 digitalWrite(trigPin, LOW); 
	 delayMicroseconds(2); 
	 digitalWrite(trigPin, HIGH);
	 delayMicroseconds(10); 
	 digitalWrite(trigPin, LOW); 
	 duration = pulseIn(echoPin, HIGH);
	 obstacle = digitalRead(obstaclePin);
 
	 //Calculate the distance (in cm) based on the speed of sound.
	 distance = (duration * 0.0344)/2;
		
		if(distance <= 20) 
		{	
			digitalWrite(buzzPin, HIGH);
			delay(1);
			digitalWrite(buzzPin, HIGH);
			delay(10);			

			if (obstacle == LOW)
			{
				do  
				{	
					draw3("Obstacle Detected!");
					draw(distance);
					draw2();
				} 
				while(oled.nextPage());
			}
			else
			{
				do  
				{	
					draw3("All Clear!");
					draw(distance);
					draw2();
				} 
				while(oled.nextPage());
			}

		}
		else
			if(distance > 20) 
			{	
				digitalWrite(buzzPin, LOW);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);

				if (obstacle == LOW)
				{
					do  
					{	
						draw3("Obstacle Detected!");
						draw(distance);
					} 
					while(oled.nextPage());
				}
				else
				{
					do  
					{	
						draw3("All Clear!");
						draw(distance);
					} 
					while(oled.nextPage());
				}
			}

 //Delay 50ms before next reading.
 delay(50);
}