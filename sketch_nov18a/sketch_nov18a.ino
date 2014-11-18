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

// Read serial data
// 0 byte indicates mode
// 1 byte indicates destination
// 2 - 6 indicates value
void ReadSerial(Settings *settings)
{
	// Read Serial
	char serialReceived[3+CHARSFORINT] = "";
	
	if(Serial.peek() != -1)
	{
		Serial.readBytes(&serialReceived[0], 19);
		
		// Read
		if(serialReceived[0] == 'r')
		{
			switch(serialReceived[1])
			{
				case '1':
					Serial.println(settings->boozeTime);
					break;
				default:
					Serial.println("Bad Input");
					break;
			}
		}
		// Write
		else if (serialReceived[0] == 'w')
		{
			switch(serialReceived[1])
			{
				case '1':
					settings->boozeTime = SerialGetValue(serialReceived, 2);
					break;
				default:
					Serial.println("Bad Input");
					break;
			}
		}
		// Execute
		else if (serialReceived[0] == 'e')
		{
		
		}
	}
}

int SerialGetValue(char* inputArray, short offset)
{
	char nummerBuffer[4] = {0};
	
	for(short i = 0; i != CHARSFORINT; i++)
	{
		nummerBuffer[i] = inputArray[i+offset];
	}	
	
	return atoi(nummerBuffer);
}