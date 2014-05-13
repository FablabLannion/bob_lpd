#include <Servo.h>

#define EnableServo 14  // activation des servos (la pin 14 est en faite la pin A0)
Servo Lleg;  // create servo object to control a servo 
Servo Rleg;
Servo Lfoot;
Servo Rfoot;

void setup_servo() {
  Lleg.attach(5);  // attaches the servo on pin x to the servo object 
  Rleg.attach(6);  // attaches the servo on pin x to the servo object 
  Lfoot.attach(4);  // attaches the servo on pin x to the servo object 
  Rfoot.attach(7);  // attaches the servo on pin x to the servo object 
  CenterServos(); //center the servos
}

void CenterServos() { 
    Lleg.write(LLcenter);    // tell servo to go to position in variable 'center' 
    Rleg.write(RLcenter);    // tell servo to go to position in variable 'center' 
    Lfoot.write(LFcenter);    // tell servo to go to position in variable 'center' 
    Rfoot.write(RFcenter);    // tell servo to go to position in variable 'center' 
    delay(100);    // waits 100ms for the servos to reach the position 
}

void TiltRightUp(byte ang, byte sp){    //tilt right up
  for (int i=0; i<=ang; i+=5){    Lfoot.write(LFcenter+i);    Rfoot.write(RFcenter+i);    delay(sp);  }
}
void TiltRightDown(byte ang, byte sp){  //tilt right down
  for (int i=ang; i>0; i-=5){    Lfoot.write(LFcenter+i);    Rfoot.write(RFcenter+i);    delay(sp);  }
}
void TiltLeftUp(byte ang, byte sp){  //tilt left up
  for (int i=0; i<=ang; i+=5){    Lfoot.write(LFcenter-i);    Rfoot.write(RFcenter-i);    delay(sp);  }
}
void TiltLeftDown(byte ang, byte sp){  //tilt left down
  for (int i=ang; i>0; i-=5){    Lfoot.write(LFcenter-i);    Rfoot.write(RFcenter-i);    delay(sp);  }
}

void LeftFootUp(char ang, byte sp){  //tilt left up
  for (int i=0; i<=ang; i+=5){    Lfoot.write(LFcenter-i);    delay(sp);  }
}
void LeftFootDown(byte ang, byte sp){  //tilt left down
  for (int i=ang; i>0; i-=5){    Lfoot.write(LFcenter-i);    delay(sp);  }
}
void RightFootUp(byte ang, byte sp){    //tilt right up
  for (int i=0; i<=ang; i+=5){    Rfoot.write(RFcenter+i);    delay(sp);  }
}
void RightFootDown(byte ang, byte sp){  //tilt right down
  for (int i=ang; i>0; i-=5){    Rfoot.write(RFcenter+i);    delay(sp);  }
}

void SwingRight(byte ang, byte sp){  //swing right
  for (int i=0; i<=ang; i+=5){    Lleg.write(LLcenter-i);    Rleg.write(RLcenter-i);    delay(sp);  }
}
void SwingRcenter(byte ang, byte sp){  //swing r->center
  for (int i=ang; i>0; i-=5){    Lleg.write(LLcenter-i);    Rleg.write(RLcenter-i);    delay(sp);  }
}

void SwingLeft(byte ang, byte sp){  //swing left
  for (byte i=0; i<=ang; i=i+5){    Lleg.write(LLcenter+i);    Rleg.write(RLcenter+i);    delay(sp);  }
}
void SwingLcenter(byte ang, byte sp){  //swing l->center
  for (byte i=ang; i>0; i=i-5){    Lleg.write(LLcenter+i);    Rleg.write(RLcenter+i);    delay(sp);  }
}

void RightLegIn(byte ang, byte sp){  //swing right
  for (int i=0; i<=ang; i+=5){    Rleg.write(RLcenter-i);    delay(sp);  }
}
void RightLegIcenter(byte ang, byte sp){  //swing r->center
  for (int i=ang; i>0; i-=5){    Rleg.write(RLcenter-i);    delay(sp);  }
}
void RightLegOut(byte ang, byte sp){  //swing right
  for (int i=0; i<=ang; i+=5){    Rleg.write(RLcenter+i);    delay(sp);  }
}
void RightLegOcenter(byte ang, byte sp){  //swing r->center
  for (int i=ang; i>0; i-=5){    Rleg.write(RLcenter+i);    delay(sp);  }
}
void LeftLegIn(byte ang, byte sp){  //swing left
  for (byte i=0; i<=ang; i=i+5){    Lleg.write(LLcenter+i);    delay(sp);  }
}
void LeftLegIcenter(byte ang, byte sp){  //swing l->center
  for (byte i=ang; i>0; i=i-5){    Lleg.write(LLcenter+i);    delay(sp);  }
}
void LeftLegOut(byte ang, byte sp){  //swing left
  for (byte i=0; i<=ang; i=i+5){    Lleg.write(LLcenter-i);    delay(sp);  }
}
void LeftLegOcenter(byte ang, byte sp){  //swing l->center
  for (byte i=ang; i>0; i=i-5){    Lleg.write(LLcenter-i);    delay(sp);  }
}

