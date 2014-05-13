#include <IRremote.h>

int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup_IR() {
	irrecv.enableIRIn(); // Start the receiver
}

int testIR() {
	if (irrecv.decode(&results)) {
		Serial.print("0x"); Serial.println(results.value, HEX);
		irrecv.resume(); // Receive the next value

		switch(results.value) {
			case codeIRav : return 1; break;
			case codeIRdt : return 2; break;
			case codeIRst : return 0; break;
			case codeIRgt : return 3; break;
			case codeIRar : return 4; break;
			case codeIRmem : memoIR=!memoIR; break;
			case codeIRmp : Vspeed=Vspeed-2; break;
			case codeIRmm : Vspeed=Vspeed+2; break;
		}
		if(Vspeed <= 0) { Vspeed=5; }
		if(Vspeed >= 55) { Vspeed=55; }
		BuzzerBeep();
	}
	if(!memoIR && !modeAuto) { return 0; } else { return Obstacle;}
}
void IRleds() {
	digitalWrite(green, LOW);
	digitalWrite(yellow, LOW);
	digitalWrite(red, LOW);

	switch(Obstacle) {
		case 1 : ledPin=yellow; break;
		case 2 : ledPin=red; break;
		case 3 : case 4 : ledPin=green; break;
	}
	digitalWrite(ledPin, HIGH);
	if(!memoIR) {	delay(200);	digitalWrite(ledPin, LOW); }
	if(Obstacle==4) {
		ledPin=red;
		digitalWrite(ledPin, HIGH);
		if(!memoIR) {	delay(200);	digitalWrite(ledPin, LOW); }
	}
}
