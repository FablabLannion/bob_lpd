/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 */

#include <IRremote.h>

int red=  12;
int yellow = 11;
int green = 10;

int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(19200);	Serial.println("Ready");
  irrecv.enableIRIn(); // Start the receiver
  
  pinMode(red, OUTPUT);		digitalWrite(red, LOW);
  pinMode(yellow, OUTPUT);	digitalWrite(yellow, LOW);
  pinMode(green, OUTPUT);	digitalWrite(green, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("0x");
    Serial.println(results.value, HEX);
    dump(&results);
    irrecv.resume(); // Receive the next value
    
    digitalWrite(red, LOW);	digitalWrite(yellow, LOW);    digitalWrite(green, LOW);
    switch(results.value) {
      case 0xFD807F : digitalWrite(yellow, HIGH); break;		// V+
      case 0xFD20DF : digitalWrite(red, HIGH); break;	// <<
      case 0xFD609F : digitalWrite(green, HIGH); break;		// >>
      case 0xFDA05F : break;								// >||
      case 0xFD906F : digitalWrite(green, HIGH); digitalWrite(red, HIGH); break;	// V-
      case 0xFD00FF : digitalWrite(yellow, HIGH); digitalWrite(green, HIGH); digitalWrite(red, HIGH); break;	// POWER
    }
  }
}

// Dumps out the decode_results structure.
// Call this after IRrecv::decode()
// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {	Serial.print("Unknown encoding: "); }
  else if (results->decode_type == NEC) {	Serial.print("Decoded NEC: "); }
  else if (results->decode_type == SONY) {	Serial.print("Decoded SONY: "); }
  else if (results->decode_type == RC5) {	Serial.print("Decoded RC5: "); }
  else if (results->decode_type == RC6) {	Serial.print("Decoded RC6: "); }
  else if (results->decode_type == JVC) {	Serial.print("Decoded JVC: "); }
  else if (results->decode_type == PANASONIC) {
	Serial.print("Decoded PANASONIC - Address: ");
	Serial.print(results->panasonicAddress,HEX);
	Serial.print(" Value: ");
  }
  Serial.print("0x");
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
}
