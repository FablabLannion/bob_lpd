/** 
* On utilise des #define plutôt que des variables sur les constantes
* cela prend moins de place en mémoire vive !! (car remplacées lors de la complilation)
*/

#define BuzzerPin 9

int ledPin;
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
int Vspeed = 30; //speed of servo

boolean modeAuto = false;	// Sélection du mode de fonctionnement
boolean memoIR = false;		// Memorisation des ordres
#define codeIRav 0xFD807F	// V+	Av
#define codeIRar 0xFD906F	// <<	Gauche
#define codeIRdt 0xFD20DF	// >||	Stop
#define codeIRgt 0xFD609F	// >>	Droite
#define codeIRst 0xFDA05F	// V-	Ar
#define codeIRmem 0xFD00FF	// POWER	Touche de mémorisation
#define codeIRfct 0xFD40BF	// FCT / STOP	Touche de fonction
#define codeIRmp 0xFD50AF	// ^	Vitesse +
#define codeIRmm 0xFD10EF	// v	Vitesse -

int Obstacle=0;

void setup(){
  setup_servo();
    
  pinMode(green, OUTPUT);       digitalWrite(green, LOW);
  pinMode(yellow, OUTPUT);      digitalWrite(yellow, LOW);
  pinMode(red, OUTPUT);         digitalWrite(red, LOW);
  
  Serial.begin(19200);  Serial.println("Ready");
  
  setup_IR();
  setup_Sonar();
 
  pinMode(BuzzerPin, OUTPUT);   digitalWrite(BuzzerPin, LOW);
  pinMode(BuzzerPin-1, OUTPUT);   digitalWrite(BuzzerPin-1, LOW);
  BuzzerBeep();
}

void loop() { 
  if(modeAuto) { Obstacle = SonarTest(); }
  Obstacle = testIR();	if(!modeAuto) { IRleds(); }
  Serial.println(Obstacle);
  switch (Obstacle){
     case 0: break;     // stop
     case 1: Forward(1,Vspeed); break;      // avant
     case 2: TurnLeft(2,Vspeed); break;     // gauche
     case 3: TurnRight(2,Vspeed); break;    // droite
     case 4: Back(2,Vspeed); break; // arriere
  }
}

void BuzzerBeep() {
	int tpstone=230;
	for (int i=0; i <= 999; i++) {
		digitalWrite(BuzzerPin, HIGH); delayMicroseconds(tpstone);
		digitalWrite(BuzzerPin, LOW); delayMicroseconds(tpstone);
	}
}
