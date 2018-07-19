/*
 Name:		DisplayOLEDSketch.ino
 Created:	6/4/2018 4:09:15 PM
 Author:	RavianXReaver
*/

#include "U8glib.h"
#include "string.h"
#include "stdio.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

#define buzzPin 22
#define echoPin 10 // Echo Pin
#define trigPin 9 // Trigger Pin
#define melodyPin 22
#define obstaclePin 11
#define reset 12

U8GLIB_SH1106_128X64 OLED(5, 4, 3, 2);  
String inputString, inputString2;
boolean complete = false;
int srmnStatus = 0;
String command2;
int triangleLoop = 0;
long duration = 0, distance = 0; // Duration used to calculate distance
int notes[] = {262, 294, 330, 349};;
int obstacle = HIGH;

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

int song = 0;
 
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];
 
      buzz(melodyPin, underworld_melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
 
    }
 
  } else {

    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];
 
      buzz(melodyPin, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
 
    }
  }
}
 
void buzz(int targetPin, long frequency, long length) 
{
  //digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) 
  { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  //digitalWrite(13, LOW);
}

//End of BuzzerMusic - Super Mario
//Begin of Buzzer Music - Star Wars



void oledFlush() 
{
	OLED.flush();
}

void spProgrammeOne(int x1,int x2,int x3,int y1,int y2,int y3) 
{ 
	OLED.setFont(u8g_font_unifont);
	OLED.setPrintPos(0, 64);
	OLED.print(triangleLoop);
	OLED.drawTriangle(x1, y1, x2, y2, x3, y3);
}

void draw(char* text) 
{
	OLED.setFont(u8g_font_04b_03r); // X = 32 chars Y = 12 chars
	OLED.setPrintPos(0,10);
	OLED.print(text);
}

void drawSS(int distance) 
{ 
	OLED.setFont(u8g_font_unifont);
	OLED.setPrintPos(0, 20);
	OLED.print("Distance: ");
	OLED.setPrintPos(80, 20);
	OLED.print(distance);
}

void drawSS2(String text)
{ 
	OLED.setFont(u8g_font_04b_03br);
	OLED.setPrintPos(0, 40);
	OLED.print(text);
}


void setup() 
{
	Serial.begin(9600);
	pinMode(buzzPin, OUTPUT);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	digitalWrite(reset, HIGH);
	pinMode(reset, OUTPUT);

	OLED.setRot180();

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

void serialEvent()
{	
	while(Serial.available())
	{	
		char charIn = (char)Serial.read();
		inputString.concat(charIn);

		if(charIn == '*')
		{	
			complete = true;
		} 
	} 
} 

String getCommand()
{	
	if(inputString.length() > 0)
	{	
		String command = inputString.substring(1, 5);
		return command;
	} 
} 

String getTextToPrint()
{	
	String text = inputString.substring(5, inputString.length() - 1);
	//inputString = "";
	return text;
} 

char* stringToCharArray(String text)
{	
	char* buf = (char*) malloc(sizeof(char)*text.length()+1);
	text.toCharArray(buf, text.length()+1);
	return buf;
	free(buf);
}

void loop()
{
  serialEvent();
  OLED.firstPage();

	if(complete)
	{	
		complete = false;
		String command = getCommand();  	
		command2 = command;
		inputString2 = inputString;

		if (command.equals("SRMN"))
		{
			srmnStatus = 1;
		}
		else
			if (command.equals("SRMF"))
			{
				srmnStatus = 0;
				delay(1);
				digitalWrite(reset, LOW);
			}

			if(command.equals("STAR"))
			{
				digitalWrite(buzzPin, HIGH);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);
			}

			if(command.equals("TEXT") && srmnStatus == 1)
			{		
				String text = getTextToPrint();

				char* buf = (char*) malloc(sizeof(char)*text.length()+1);
				text.toCharArray(buf, text.length()+1);
			
				Serial.write(buf);	
				free(buf);				
			}
			else
				if(command.equals("TEXT") && srmnStatus == 0)
				{
					String text = getTextToPrint();

					char* buf = (char*) malloc(sizeof(char)*text.length()+1);
					text.toCharArray(buf, text.length()+1);			

					do  
					{	
						draw(stringToCharArray(text));
					} 
					while(OLED.nextPage());
				}

			if(command.equals("STOP"))
			{
				digitalWrite(buzzPin, HIGH);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);
			}
	}

	if(command2.equals("PP1S"))
	{
		do  
		{	
			if(triangleLoop%4==0)
			{	
				spProgrammeOne(40,60,80,20,60,20);
			}
			else
				if(triangleLoop%4==1)
				{
					spProgrammeOne(80,40,80,20,40,60);
				}		
				else
					if(triangleLoop%4==2)
					{	
						spProgrammeOne(60,40,80,20,60,60);
					}
					else
						if(triangleLoop%4==3)
						{
							spProgrammeOne(40,80,40,60,40,20);
						}		
		} 
		while(OLED.nextPage());

		triangleLoop++;
	}

	if(command2.equals("SSSS") && srmnStatus ==  0)
	{
		String ssbuzzerCommand	= inputString2.substring(5, 6);
		String ssRange			= inputString2.substring(6, 9);
		String ssMessage		= inputString2.substring(9, inputString2.length() - 1);
		int range = ssRange.toInt();
		digitalWrite(trigPin, LOW); 
		delayMicroseconds(2); 
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10); 
		digitalWrite(trigPin, LOW); 
		duration = pulseIn(echoPin, HIGH);
 
		//Calculate the distance (in cm) based on the speed of sound.
		distance = (duration * 0.0344)/2;

		if(ssbuzzerCommand.equals("0"))
		{
			if(distance <= range)
			{	
				do  
				{	
					drawSS(distance);
					drawSS2(ssMessage);
				} 
				while(OLED.nextPage());
			}
			else
				if(distance > range) 
				{	
					do  
					{	
						drawSS(distance);
					} 
					while(OLED.nextPage());				
				}
		}
		else
		{
			if(distance <= range)
			{	
				digitalWrite(buzzPin, HIGH);
				delay(1);
				digitalWrite(buzzPin, HIGH);
				delay(10);	

				do  
				{	
					drawSS(distance);
					drawSS2(ssMessage);
				} 
				while(OLED.nextPage());
			}
			else
				if(distance > range) 
				{	
					digitalWrite(buzzPin, LOW);
					delay(1);
					digitalWrite(buzzPin, LOW);
					delay(10);

					do  
					{	
						drawSS(distance);
					} 
					while(OLED.nextPage());				
				}
		}
	}
	else
	if(command2.equals("SSSS") && srmnStatus == 1)
	{
		String ssbuzzerCommand	= inputString2.substring(5, 6);
		String ssRange			= inputString2.substring(6, 9);
		String ssMessage		= inputString2.substring(9, inputString2.length() - 1);
		int range = ssRange.toInt();
		digitalWrite(trigPin, LOW); 
		delayMicroseconds(2); 
		digitalWrite(trigPin, HIGH);
		delayMicroseconds(10); 
		digitalWrite(trigPin, LOW); 
		duration = pulseIn(echoPin, HIGH);
 
		//Calculate the distance (in cm) based on the speed of sound.
		distance = (duration * 0.0344)/2;

		if(ssbuzzerCommand.equals("0"))
		{
			if(distance <= range)
			{	
				Serial.write(stringToCharArray(ssMessage));	
			}
			else
				if(distance > range) 
				{	
					Serial.write(distance);					
				}
		}
		else
		{
			if(distance <= range)
			{	
				digitalWrite(buzzPin, HIGH);
				delay(1);
				digitalWrite(buzzPin, HIGH);
				delay(10);	

				Serial.write(stringToCharArray(ssMessage));	
			}
			else
				if(distance > range) 
				{	
					digitalWrite(buzzPin, LOW);
					delay(1);
					digitalWrite(buzzPin, LOW);
					delay(10);
					
					Serial.write(distance);			
				}
		}
	}
	
	if(command2.equals("SISS"))
	{
		String ssbuzzerCommand	= inputString2.substring(5, 6);
		String ssMessage		= inputString2.substring(6, inputString2.length() - 1);
		obstacle = digitalRead(obstaclePin);

		if(ssbuzzerCommand.equals("0"))
		{
			if(obstacle == LOW)
			{		
				digitalWrite(buzzPin, LOW);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);

				do  
				{	
					drawSS2(ssMessage);
				} 
				while(OLED.nextPage());	
			}
			else
			{
				digitalWrite(buzzPin, LOW);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);

				do  
				{	
					drawSS2("");
				} 
				while(OLED.nextPage());	
			}
		}
		else
		{
			if(obstacle == LOW)
			{		
				digitalWrite(buzzPin, HIGH);
				delay(1);
				digitalWrite(buzzPin, HIGH);
				delay(10);

				do  
				{	
					drawSS2(ssMessage);
				} 
				while(OLED.nextPage());	
			}
			else
			{	
				digitalWrite(buzzPin, LOW);
				delay(1);
				digitalWrite(buzzPin, LOW);
				delay(10);

				do  
				{	
					drawSS2("");
				} 
				while(OLED.nextPage());	
			}
		}
	}

	if(command2.equals("MSMS"))
	{	
		sing(1);
		sing(1);
		sing(2);
	}

	if(command2.equals("MSWS"))
	{
	 
	}

	inputString = "";
	delay(100);
}
