#include "Servo.h"
#define servLl 5
#define servRl 6
#define servLf 7
#define servRf 4
int RFcenter = 105;    // variable to store the center servo position 
int LLcenter = 73;
int RLcenter = 103;
int LFcenter = 94;
int tAngle = 30; //tilt angle
int uAngle = 35; //turn angle
int sAngle = 35; //swing angle

#define EnableServo 14

Servo Lleg;  // createS servo object to control a servo 
Servo Rleg;
Servo Lfoot;
Servo Rfoot;
int valtest=0;
int regl=0;
char *test[]={
	"Rleg",
	"Lleg",
	"Rfoot",
	"Lfoot",
};
String msg="";

void setup() {
	Lleg.attach(servLl);  Rleg.attach(servRl);  Lfoot.attach(servLf);  Rfoot.attach(servRf);
	Serial.begin(19200);
	Serial.println(F("Detail des touches utilisees :"));
	Serial.println(F("     a => Changement de servo vers la gauche"));
	Serial.println(F("     z => Changement de servo vers la droite"));
	Serial.println(F("     s => +1     d => +5     f => +10"));
	Serial.println(F("     x => -1     c => -5     v => -10"));
	Serial.println(F("     q => Valeur"));
	Serial.println(F(""));
	
	Serial.println(F("Ordre :"));
	int size = sizeof(test) / sizeof(int);
	for (int ite = 0; ite < size; ite++) { Serial.print(F("     ")); Serial.println(test[ite]); }
	Serial.println(F(""));
	
//	Serial.print(F("Reglage ")); Serial.println(test[regl-1]);
	testVal(1);
	Serial.println(msg);
}
void loop(){
	if(Serial.available() > 0) {
		int txt = Serial.read();
		msg="";
		
		switch(txt) {
			case 's' : valtest = valtest + 1;		msg=" +1 "; break;
			case 'x' : valtest = valtest - 1;		msg=" -1 "; break;
			case 'd' : valtest = valtest + 5;		msg=" +5 "; break;
			case 'c' : valtest = valtest - 5;		msg=" -5 "; break;
			case 'f' : valtest = valtest + 10;		msg=" +10 "; break;
			case 'v' : valtest = valtest - 10;		msg=" -10 "; break;
			case 'a' : testVal(-1); break;
			case 'z' : testVal(+1); break;
//			case 'z' : regl++; if(regl==5) { regl=1; } msg="Reglage de "; msg.concat(test[regl-1]); valtest = testVal(regl); break;
			case 'q' : testVal(0); regle(); msg="Reglage fini"; valtest=0; break;
			default : msg = "Touche inconnue."; break;
		}
	
		if(regl==1) { Rleg.write(valtest); }
		if(regl==2) { Lleg.write(valtest); }
		if(regl==3) { Rfoot.write(valtest); }
		if(regl==4) { Lfoot.write(valtest); }
		Serial.println(msg);
		if(valtest) { Serial.println(valtest); }
	}
}
  
void regle(){	//routine de sous-reglage
	Serial.println(F(""));
	Serial.println(F("Valeurs definitives :"));
	Serial.print(F("int RFcenter = "));		Serial.print(RFcenter);		Serial.println(";");
	Serial.print(F("int LLcenter = "));		Serial.print(LLcenter);		Serial.println(";");
	Serial.print(F("int RLcenter = "));		Serial.print(RLcenter);		Serial.println(";");
	Serial.print(F("int LFcenter = "));		Serial.print(LFcenter);		Serial.println(";");
	regl=0;
}
int testVal(int x) {
	if(regl==1) { RLcenter=valtest; }
	else if(regl==2) { LLcenter=valtest; }
	else if(regl==3) { RFcenter=valtest; }
	else if(regl==4) { LFcenter=valtest; }
	
	regl = regl + x;
	if(regl==0) { regl=4; }
	if(regl==5) { regl=1; }
	msg="Reglage de "; msg.concat(test[regl-1]);
	
	if(regl==1) { valtest=RLcenter; }
	else if(regl==2) { valtest=LLcenter; }
	else if(regl==3) { valtest=RFcenter; }
	else if(regl==4) { valtest=LFcenter; }
}





