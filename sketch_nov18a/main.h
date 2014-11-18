typedef struct Settings {
	int boozeTime;
};

void ReadSerial(Settings*);
int SerialGetValue(char*, short);