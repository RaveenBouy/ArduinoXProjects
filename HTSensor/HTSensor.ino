#include "DHTlib/dht.h"

dht DHT;

#define DHT11_PIN	19
#define potPin		4

int val = 0;       // variable to store the value coming from the sensor

void setup()
{
	Serial.begin(9600);
	Serial.println("DHT TEST PROGRAM ");
	Serial.print("LIBRARY VERSION: ");
	Serial.println(DHT_LIB_VERSION);
	Serial.println();
	Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  val = analogRead(potPin);    // read the value from the sensor
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
		Serial.print("Unknown error,\t"); 
		break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
	Serial.println(val);
  delay(2000);
}