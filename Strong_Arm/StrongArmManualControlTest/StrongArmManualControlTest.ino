//start time: 5:00 PM
//lets take no longer than 15 min
//Enable pin
const int enaneg1 = 22;
//Direction pin
const int dirneg1 = 24;
//Pulse pin
const int pulneg1 = 26;
//Enable pin
const int enaneg2 = 30;
//Direction pin
const int dirneg2 = 25;
//Pulse pin
const int pulneg2 = 27;

//current MICROSECOND COUNT
unsigned long currentMillis = 0;
//MICROSECOND COUNT at the last encoder count
unsigned long previousMillis = 0;
//number of microseconds between switching pins from high to low and vice versa
int stepInterval = 500;
int noStep = 1200;
int x = 0;
int inByte = 0;

//if pulse pin is HIGH, this is true
boolean stepPosition = false;
boolean speedDirection = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
  Serial.flush();
  pinMode(enaneg1,OUTPUT);
  pinMode(dirneg1,OUTPUT);
  pinMode(pulneg1,OUTPUT);
  pinMode(enaneg2,OUTPUT);
  pinMode(dirneg2,OUTPUT);
  pinMode(pulneg2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = 0;
  while ( Serial.available() > 0) {
    inByte = Serial.read();
  while(x < noStep){
    digitalWrite(dirneg1,LOW);
    digitalWrite(dirneg2, HIGH);
      digitalWrite(pulneg1,HIGH);
      digitalWrite(pulneg2, HIGH);
      delayMicroseconds(500);
      digitalWrite(pulneg1,LOW);
      digitalWrite(pulneg2, LOW);
      delayMicroseconds(500);
      x++;
    } 
  delay(1000);
  x = 0;
  while (x < noStep){
    digitalWrite(dirneg1,HIGH);
    digitalWrite(dirneg2, LOW);
      digitalWrite(pulneg1,HIGH);
      digitalWrite(pulneg2, HIGH);
      delayMicroseconds(500);
      digitalWrite(pulneg1,LOW);
      digitalWrite(pulneg2, LOW);
      delayMicroseconds(500);
      x++;
  }
  delay(1000);
  x = 0;
}
