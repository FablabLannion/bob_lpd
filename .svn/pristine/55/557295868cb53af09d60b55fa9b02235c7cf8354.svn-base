long cm;                // variable pour stocker la distance de l'objet en cm
#define SONAR_TRIGGER 3	// Arduino pin tied to trigger pin on the ultrasonic sensor.
#define SONAR_ECHO 2	// Arduino pin tied to echo pin on the ultrasonic sensor.

void setup_Sonar() {
	pinMode(SONAR_TRIGGER, OUTPUT);	digitalWrite(SONAR_TRIGGER, LOW);
	pinMode(SONAR_ECHO, INPUT);
}

int SonarTest() {
	cm = SonarRead(3); // send ping and get distance in cm avec nb echantillons
	Serial.print("cm : ");
	Serial.println(cm);
	if(cm >= 25) {		SonarBlink(cm, green);	return 1; }	// objet lointain
	else if(cm >= 10) {	SonarBlink(cm, yellow);	return 2; }	// distance moyenne
	else {				SonarBlink(cm, red);	return 4; }	// objet tr�s proche
}
int SonarRead(int samples){
	long howfar=0;
	for (int i=samples; i>0; i--){
		digitalWrite(SONAR_TRIGGER,LOW);
		delayMicroseconds(5);                                                                              
		digitalWrite(SONAR_TRIGGER,HIGH);
		delayMicroseconds(15);
		digitalWrite(SONAR_TRIGGER,LOW);
		howfar+=pulseIn(SONAR_ECHO,HIGH, 2000);
	}
	howfar=howfar/samples;
	howfar=howfar*0.01657; //how far away is the object in cm
	if(howfar==0) { howfar=36; }
	return round(howfar);
}
void SonarBlink(int pause, int ledPin) {
	//La fonction ci-dessous fait clignoter la LED correspondant � la distance.
	//Le clignotement est de plus en plus rapide � mesure que l'objet se rapproche.
	pause = pause * 10;
	digitalWrite(ledPin, HIGH);		delay(pause);
	digitalWrite(ledPin, LOW);		delay(10);
}


