//Enable pin
const int enaneg = 22;
//Direction pin
const int dirneg = 24;
//Pulse pin
const int pulneg = 26;

//Encoder A pin
const int encoderA = 18;
//Encoder B pin
const int encoderB = 19;

//number of encoder counts in array
int counter = 0;

//current MICROSECOND COUNT
unsigned long currentMillis = 0;

//MICROSECOND COUNT at the last encoder count
unsigned long previousMillis = 0;

//time that the pulses began
unsigned long runMillis = 0;

//number of microseconds between switching pins from high to low and vice versa
int stepInterval = 500;

//if pulse pin is HIGH, this is true
boolean stepPosition = false;

//number of steps in one loop of the code
int noStep = 200; //was 200

//declare arrays where encoder pulse times are stored
double encoderTimeA[200];
double encoderTimeB[200];

//things for printing array to screen
//integer which loops through for loop, printing array to screen
int count = 0;
double lastTime = 0;
double totalTime = 0;
int encoderCount = 0;
boolean speedDirection = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(enaneg,OUTPUT);
  pinMode(dirneg,OUTPUT);
  pinMode(pulneg,OUTPUT);

  pinMode(encoderA,INPUT);
  pinMode(encoderB,INPUT);

  //if encoder pins go to HIGH, time when encoder pulsed is recorded
  attachInterrupt(digitalPinToInterrupt(encoderA), senseEncoderA, RISING);
  attachInterrupt(digitalPinToInterrupt(encoderB), senseEncoderB, RISING);
  Serial.begin(9600);
}

//adds new encoder pulse time to the array
void senseEncoderA(){
  encoderTimeA[counter] = currentMillis - runMillis;
  counter++; 
}

//adds new encoder pulse time to the array
void senseEncoderB(){
  encoderTimeB[counter] = currentMillis - runMillis;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int x = 0;
  counter = 0;
  //sets beginning time of the pulses
  runMillis = micros();

  //steps motor and writes times of encoder pulses to 
  while(x < noStep){
    currentMillis = micros();

    //these two if statements pulse the motor
    
    //runs when more time than the step interval has elapsed - sets pulse pin to HIGH
    if(currentMillis - previousMillis >= stepInterval && !stepPosition){
      digitalWrite(pulneg,HIGH);
      stepPosition = true;
      //Serial.println("yeet");
      previousMillis = currentMillis;
      if(!speedDirection){
        stepInterval++;
        if(stepInterval > 1200){
          speedDirection = true;
        }
      } else {
        stepInterval--;
        if(stepInterval < 500){
          speedDirection = false;
        }
      }
    }

    //same as above but sets step pin to LOW
    if(currentMillis - previousMillis >= stepInterval && stepPosition){
      digitalWrite(pulneg,LOW);
      stepPosition = false;
      previousMillis = currentMillis;
      x++;
    }

//  this code spat out encoder values in real time, commented out to not lag the arduino
    
//    if(lastEncoderA != encoderAPos){
//      if(encoderAPos == 0)
//        Serial.println("A is HIGH");
//    } else {
//        Serial.println("A is LOW");
//        Serial.println(digitalRead(encoderA));
//    }
//    if(lastEncoderB != encoderBPos){
//      if(encoderBPos == 0)
//        Serial.println("B is HIGH");
//    } else {
//        Serial.println("B is LOW");
//    }    
//    lastEncoderA = encoderAPos;
//    lastEncoderB = encoderBPos;
   }

//this code prints the encoder arrays to the screen
  count = 0;
  lastTime = 0;
  totalTime = 0;
  encoderCount = 0;
  Serial.print("\n Array start \n");
// while (count < counter){
//      if (encoderTimeA[count] != 0){
//        totalTime += encoderTimeA[count] - lastTime;
//        lastTime = encoderTimeA[count];
//        encoderCount++;
//      }
//    ////Serial.print(encoderTimeA[count]);
//    ////Serial.print(" ");
//    encoderTimeA[count] = 0;
//    encoderTimeB[count] = 0;
//    count++;
//  }
////  double avgTime = totalTime/encoderCount;
////  double avgVelocity = (encoderCount/1000) * 360/(avgTime * 0.000001);
////  Serial.print(avgVelocity);
//  ////Serial.print("\n");
//  ////Serial.print(counter);
//  ////Serial.print("\n Array over");
}
