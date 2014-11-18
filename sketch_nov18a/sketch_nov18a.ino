#include <SoftwareSerial.h>
#define DEBUG true
#include "main.h"

void setup()
{
	//Serieele communicatie klaarzetten voor de computer
	Serial.begin(9600);
	
	// Wachten tot serieel verbonden is
	while(!Serial)
	{
		continue;
	}
}

void loop()
{
	//Initializeren van de instellingen voor het gebruik
	Settings *settings = (Settings*)malloc(sizeof(Settings));
	settings->boozeTime = 10;
	
	//Superloop
	while(true)
	{
		ReadSerial(settings);
	}
	
	if(DEBUG)
	{
		delay(10);
	}
}

void ReadSerial(Settings *settings)
{
	// Read Serial
	char serialReceived[20] = "";
	
	if(Serial.peek() != -1)
	{
		Serial.readBytes(&serialReceived[0], 19);
		Serial.println(settings->boozeTime);
		Serial.println(serialReceived);
	}
}