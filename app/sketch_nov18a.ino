#include <SoftwareSerial.h>

typedef struct Settings {
	int boozeTime;
};

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
	
	//Superloop
	while(true)
	{
		char serialReceived[20] = "";
		
		if(Serial.peek())
		{
			Serial.readBytes(&serialReceived[0], 19);
			Serial.println(serialReceived);
		}
	}
}