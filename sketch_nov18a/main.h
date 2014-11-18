#define DEBUG true
#define CHARSFORINT 4

#include <SoftwareSerial.h>

typedef struct Settings {
	int boozeTime;
};

void ReadSerial(Settings*);
int SerialGetValue(char*, short);