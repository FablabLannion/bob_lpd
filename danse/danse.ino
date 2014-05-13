#define red 12
#define yellow 11
#define green 10

int RFcenter = 105;    // variable to store the center servo position 
int LLcenter = 73;
int RLcenter = 103;
int LFcenter = 94;
int tAngle = 30; //tilt angle
int uAngle = 35; //turn angle
int sAngle = 35; //swing angle

void setup(){
	setup_servo();
	
	pinMode(green, OUTPUT);	digitalWrite(green, LOW);
	pinMode(yellow, OUTPUT);	digitalWrite(yellow, LOW);
	pinMode(red, OUTPUT);		digitalWrite(red, LOW);
	
	setup_buzzer();
	
	Serial.begin(19200);	Serial.println("Ready");
	BuzzerBeep();	delay(1000);
	if(0) {
		Serial.println("Demonstration des mouvements (Nb bip = numero");
		Serial.println("	Mouvements w");
		play_rtttl("test_mouvement:d=4,o=6,b=127:1w,8c,1p,2w,8c,8c,1p,3w,8c,8c,8c,1p,4w,8c,8c,8c,8c,1p,5w,8c,8c,8c,8c,8c,1p,6z,8c,8c,8c,8c,8c,8c,1p");
		Serial.println("	Mouvements x");
		play_rtttl("test_mouvement:d=4,o=6,b=127:1x,8c,1p,2x,8c,8c,1p,3x,8c,8c,8c,1p,4x,8c,8c,8c,8c,1p,5x,8c,8c,8c,8c,8c,1p,6z,8c,8c,8c,8c,8c,8c,1p,");
		Serial.println("	Mouvements z");
		play_rtttl("test_mouvement:d=4,o=6,b=127:1z,8c,1p,2z,8c,8c,1p,3z,8c,8c,8c,1p");
		Serial.println("	Mouvements y");
		play_rtttl("test_mouvement:d=4,o=6,b=127:1y,8c,1p,2y,8c,8c,1p,3y,8c,8c,8c,1p,4y,8c,8c,8c,8c,1p,5y,8c,8c,8c,8c,8c,1p,6z,8c,8c,8c,8c,8c,8c,1p,");
		Serial.println("	Demonstration finie");
	}
	play_rtttl("MacGyverLong:d=4,o=6,b=150:8b4,8e5,8a5,8b5,a5,8e5,8b4,8p,8e5,8a5,8b5,8a5,8e5,b4,8p,8e5,8a5,8b5,a5,8e5,8b4,8p,8a5,8d,8c,8d,8c,8b5,8a5,8b4,8e5,8a5,8b5,a5,8e5,8b4,8p,8e5,8a5,8b5,8a5,8e5,b4,8p,8e5,8a5,8b5,a5,8e5,8b4,8p,8a5,8d,8c,8d,8c,8b5,8a5,b5,8p,2b5,8p,b5,8p,a5,d.,b5,8p,2b5,8p,8b5,8p,2a5,p,8c,8c,8c,8c,8c,8c,2b5,16p,8f#5,8a5,8p,2g5,8p,8c,8c,8p,b5,8a5,8b5,8a5,8g5,8p,e,2a5,16p,8c,8c,8p,2b5,8p,8f#5,8a5,8p,2g5,8p,8c,8c,8p,4b5,8a5,8b5,8a5,8g5,8p,4e,2a5,2b5,32p,8c,8b5,8a5,c,8b5,8a5,8d,8c,8b5,d,8c,8b5,e,8d,8e,f#,b5,g,8p,f#,f,b5,8g,8e,8b5,8f#,8d,8a5,8e,8c,8g5,8d,8b5,8g5,8c,8e5,8b5,8d5,8c,8b5,8a5,8g5,a#5,a5,8g,8g5,8d,8g5,8d#,8d#5,8a#5,8a5,8g5,8g4,8d5,8g4,8d#5,8g4,8a#4,8a4,8g4,8g4,8g4,8g4,8g4,8g4,8g4");	delay(1000);
	BuzzerBeep();	delay(1000);
}

void loop() {
	play_rtttl("MacGyver:d=4,o=6,b=127:1z,1y,8c,8c,8c,8c,8c,8c,2y,2b5,8f_5,8a5,3y,8p,2g5,8c,8c,4y,8p,b5,8a5,8b5,8a5,8g5,5y,8p,e,a.5,16p,6y,3z,b.5,2z,16p,c,8b5,8a5,c");	CenterServos(); delay(1000);
//	play_rtttl("MacGyverLong:d=4,o=6,b=150:8b4,8e5,8a5,8b5,a5,8e5,8b4,8p,8e5,8a5,8b5,8a5,8e5,b4,8p,8e5,8a5,8b5,a5,8e5,8b4,8p,8a5,8d,8c,8d,8c,8b5,8a5,8b4,8e5,8a5,8b5,a5,8e5,8b4,8p,8e5,8a5,8b5,8a5,8e5,b4,8p,8e5,8a5,8b5,a5,8e5,8b4,8p,8a5,8d,8c,8d,8c,8b5,8a5,b5,8p,2b5,8p,b5,8p,a5,d.,b5,8p,2b5,8p,8b5,8p,2a5,p,8c,8c,8c,8c,8c,8c,2b5,16p,8f#5,8a5,8p,2g5,8p,8c,8c,8p,b5,8a5,8b5,8a5,8g5,8p,e,2a5,16p,8c,8c,8p,2b5,8p,8f#5,8a5,8p,2g5,8p,8c,8c,8p,4b5,8a5,8b5,8a5,8g5,8p,4e,2a5,2b5,32p,8c,8b5,8a5,c,8b5,8a5,8d,8c,8b5,d,8c,8b5,e,8d,8e,f#,b5,g,8p,f#,f,b5,8g,8e,8b5,8f#,8d,8a5,8e,8c,8g5,8d,8b5,8g5,8c,8e5,8b5,8d5,8c,8b5,8a5,8g5,a#5,a5,8g,8g5,8d,8g5,8d#,8d#5,8a#5,8a5,8g5,8g4,8d5,8g4,8d#5,8g4,8a#4,8a4,8g4,8g4,8g4,8g4,8g4,8g4,8g4");	CenterServos(); delay(1000);
	BuzzerBeep();	delay(1000);
}

