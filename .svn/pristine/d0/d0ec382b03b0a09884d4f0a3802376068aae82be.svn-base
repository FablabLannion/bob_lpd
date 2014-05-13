void TurnLeft(byte Steps, byte Speed){
  digitalWrite(EnableServo,HIGH);
  TiltRightUp(tAngle, Speed);
  for (byte j=0; j<Steps; ++j){
    SwingRight(sAngle, Speed); 
    TiltRightDown(tAngle, Speed);
    TiltLeftUp(tAngle, Speed);
    SwingRcenter(sAngle, Speed);
    SwingLeft(sAngle, Speed);
    TiltLeftDown(tAngle, Speed);
    TiltRightUp(tAngle, Speed);
    SwingLcenter(sAngle, Speed);
  }
  TiltRightDown(tAngle, Speed);
  digitalWrite(EnableServo,LOW);
}
void TurnRight(byte Steps, byte Speed){
  digitalWrite(EnableServo,HIGH);
  TiltLeftUp(tAngle, Speed);
  for (byte j=0; j<Steps; ++j){
    SwingLeft(sAngle, Speed); 
    TiltLeftDown(tAngle, Speed);
    TiltRightUp(tAngle, Speed);
    SwingLcenter(sAngle, Speed);
    SwingRight(sAngle, Speed);
    TiltRightDown(tAngle, Speed);
    TiltLeftUp(tAngle, Speed);
    SwingRcenter(sAngle, Speed);
  }
  TiltLeftDown(tAngle, Speed);
  digitalWrite(EnableServo,LOW);
}

void Forward(byte Steps, byte Speed){
  digitalWrite(EnableServo,HIGH);
  TiltLeftUp(uAngle, Speed);
  delay(20);
  for (byte j=0; j<Steps; ++j){
    LeftLegIn(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    delay(20);
    LeftLegIcenter(sAngle, Speed);
    RightLegOut(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    delay(20);
    RightLegOcenter(sAngle, Speed);
  }
  TiltLeftDown(uAngle, Speed);
  digitalWrite(EnableServo,LOW);
}
void Back(byte Steps, byte Speed){
  digitalWrite(EnableServo,HIGH);
  TiltRightUp(uAngle, Speed);
  delay(20);
  for (byte j=0; j<Steps; ++j){
    RightLegIn(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    delay(20);
    RightLegIcenter(sAngle, Speed);
    LeftLegOut(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    delay(20);
    LeftLegOcenter(sAngle, Speed);
  }
  TiltRightDown(uAngle, Speed);
  digitalWrite(EnableServo,LOW);
}

