/*
 * Motor 1 (Link 1)
 */
//Enable pin
const int enaneg1 = 22;
//Direction pin
const int dirneg1 = 24;
//Pulse pin
const int pulneg1 = 26;
//Encoder A pin
const int encoderA1 = 18;
//Encoder B pin
const int encoderB1 = 19;

//Target position (in steps; CHANGE TO DEGREEES) for Motor 1
int posDesired1 = 0; //-938; //1.5 scaling

//number of encoder counts in array (correspond to steps which correspond to position); EDIT TO MAKE A POSITION VARIABLE
int encoderCount1 = 0;

/*
 * Motor 2 (Link 2)
 */
//Enable pin
const int enaneg2 = 23;
//Direction pin
const int dirneg2 = 25;
//Pulse pin
const int pulneg2 = 27;
//Encoder A pin
const int encoderA2 = 2;
//Encoder B pin
const int encoderB2 = 3;

//Target position (in steps; CHANGE TO DEGREEES) for Motor 1
int posDesired2 = 0; //-893; //45 degrees; 1000 counts per rotation divided by 2???

//number of encoder counts in array (correspond to steps which correspond to position); EDIT TO MAKE A POSITION VARIABLE
int encoderCount2 = 0;

//current MICROSECOND COUNT
unsigned long currentMillis1 = 0;

//MICROSECOND COUNT at the last encoder count
unsigned long previousMillis1 = 0;

//current MICROSECOND COUNT
unsigned long currentMillis2 = 0;

//MICROSECOND COUNT at the last encoder count
unsigned long previousMillis2 = 0;

boolean stepPosition1 = false;
boolean stepPosition2 = false;

//Offset value (to make stopping smooth, since could bounce between positions)
const int EPSILON = 1;

//Delay of number of microseconds between switching pins from high to low and vice versa
int stepInterval = 500;

//character array for our serial input command stream
char command[8];
//what we get from the serial communication from the Pi
String serialInfo;

//Limit switch input to know when to normalize position to 0
const int limitSwitch = 40;

void setup() {
  //Motor 1 Setup
  pinMode(enaneg1,OUTPUT);
  pinMode(dirneg1,OUTPUT);
  pinMode(pulneg1,OUTPUT);
  pinMode(encoderA1,INPUT);
  pinMode(encoderB1,INPUT);

  //Motor 2 Setup
  pinMode(enaneg2,OUTPUT);
  pinMode(dirneg2,OUTPUT);
  pinMode(pulneg2,OUTPUT);
  pinMode(encoderA2,INPUT);
  pinMode(encoderB2,INPUT);

  //Begin Serial (for communication to the Pi)
  Serial.begin(9600);

  //if encoder pins go to HIGH, time when encoder pulsed is recorded
  attachInterrupt(digitalPinToInterrupt(encoderA1), senseEncoderA1, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderA2), senseEncoderA2, RISING);
}

//adds new encoder pulse for Motor 1 "position" count
void senseEncoderA1(){
  if(digitalRead(encoderB1) == HIGH){
    encoderCount1--;
  }
  else {
    encoderCount1++;
  }
}

//adds new encoder pulse for Motor 2 "position" count
void senseEncoderA2(){
  if(digitalRead(encoderB2) == HIGH){
    encoderCount2--;
  }
  else {
    encoderCount2++;
  }
}

int convertMotor1Pos(int pos1) {
  return pos1*7500/360;
}

int convertMotor2Pos(int pos2) {
  return pos2*5000/(0.7*360);
}

void loop() {  
// Check if we have a serial command to write to a position from the Pi

  if(Serial.available() > 0) {

    //Read our serial input until our end packet
    serialInfo = Serial.readStringUntil('E');

  }

  //Split up our received command into a character array; will need this to check which motor to command
    serialInfo.toCharArray(command, 8);

    //Get our desired position ; note: current encoding assumption is M(1/2)D(P/N)XXXXE, meaning position is a degree value
     if(command[1] == '1') {
          if(command[2] == 'D') {
            posDesired1 = serialInfo.substring(4).toInt();
            //posDesired1 = convertMotor1Pos(posDesired1);
            if(command[3] == 'N') {
              posDesired1 = -1*posDesired1;
            }
           // Serial.print("PD1: ");
            //Serial.println(posDesired1);
          }
      }
      else if(command[1] == '2') {
        if(command[2] == 'D'){
            posDesired2 = serialInfo.substring(4).toInt();
            //posDesired2 = convertMotor2Pos(posDesired2);
            if(command[3] == 'N') {
              posDesired2 = -1*posDesired2;
            }
            //Serial.print("PD2: ");
            //Serial.println(posDesired2);
        }
      }

  // WITH DEGREES
  /*
    //Split up our received command into a character array; will need this to check which motor to command
    serialInfo.toCharArray(command, 8);
    //Get our desired position ; note: current encoding assumption is M(1/2)D(P/N)XXXE, meaning position is a degree value
     if(command[1] == '1') {
          if(command[2] == 'D') {
            posDesired1 = serialInfo.substring(4).toInt();
            posDesired1 = convertMotor1Pos(posDesired1);
            if(command[3] == 'N') {
              posDesired1 = -1*posDesired1;
            }
           // Serial.print("PD1: ");
            //Serial.println(posDesired1);
          }
      }
      else if(command[1] == '2') {
        if(command[2] == 'D'){
            posDesired2 = serialInfo.substring(4).toInt();
            posDesired2 = convertMotor2Pos(posDesired2);
            if(command[3] == 'N') {
              posDesired2 = -1*posDesired2;
            }
            //Serial.print("PD2: ");
            //Serial.println(posDesired2);
        }
      }
      */

//  //Move Motor 1
//    if (posDesired1-EPSILON>encoderCount1){
//      digitalWrite(dirneg1, LOW);
//      digitalWrite(pulneg1,HIGH);
//      delayMicroseconds(stepInterval);
//      digitalWrite(pulneg1,LOW);
//      delayMicroseconds(stepInterval);
//    }
//    else if (posDesired1+EPSILON<encoderCount1){
//      digitalWrite(dirneg1, HIGH);
//      digitalWrite(pulneg1,HIGH);
//      delayMicroseconds(stepInterval);
//      digitalWrite(pulneg1,LOW);
//      delayMicroseconds(stepInterval);
//    }
//
//  //Move Motor 2
//      if (posDesired2-EPSILON>encoderCount2){
//      digitalWrite(dirneg2, LOW);
//      digitalWrite(pulneg2,HIGH);
//      delayMicroseconds(stepInterval);
//      digitalWrite(pulneg2,LOW);
//      delayMicroseconds(stepInterval);
//    }
//    else if (posDesired2+EPSILON<encoderCount2){
//      digitalWrite(dirneg2, HIGH);
//      digitalWrite(pulneg2,HIGH);
//      delayMicroseconds(stepInterval);
//      digitalWrite(pulneg2,LOW);
//      delayMicroseconds(stepInterval);
//    }

  //posDesired1 = 500;
  //posDesired2 = 0;

  //  //steps motor and writes times of encoder pulses to
    currentMillis1 = currentMillis2 = micros();
    //these two if statements pulse the motor
    if(encoderCount1 < posDesired1-EPSILON)
        digitalWrite(dirneg1, LOW);
     else
        digitalWrite(dirneg1, HIGH);
    //runs when more time than the step interval has elapsed - sets pulse pin to HIGH
    if(encoderCount1 < posDesired1-EPSILON || encoderCount1 > posDesired1+EPSILON){
      if(currentMillis1 - previousMillis1 >= stepInterval){
        if(stepPosition1){
          digitalWrite(pulneg1,LOW);
          stepPosition1 = false;
          previousMillis1 = currentMillis1;
        } else {
            digitalWrite(pulneg1,HIGH);
            stepPosition1 = true;
            //Serial.println("yeet");
            previousMillis1 = currentMillis1;
          }
        }
    }

    //these two if statements pulse the motor
    if(encoderCount2 < posDesired2-EPSILON)
        digitalWrite(dirneg2, LOW);
     else
        digitalWrite(dirneg2, HIGH);
    //runs when more time than the step interval has elapsed - sets pulse pin to HIGH
    if(encoderCount2 < posDesired2-EPSILON || encoderCount2 > posDesired2+EPSILON){
      if(currentMillis2 - previousMillis2 >= stepInterval){
        if(stepPosition2){
          digitalWrite(pulneg2,LOW);
          stepPosition2 = false;
          previousMillis2 = currentMillis2;
        } else {
            digitalWrite(pulneg2,HIGH);
            stepPosition2 = true;
            //Serial.println("yeet");
            previousMillis2 = currentMillis2;
          }
        }
    }
    //Serial.print("Enc2: ");
    //Serial.println(encoderCount2);
//     delay(.05);
//    Serial.println(encoderCount1);

}
