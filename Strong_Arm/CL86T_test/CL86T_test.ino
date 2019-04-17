const int enaneg = 22;
const int dirneg = 24;
const int pulneg = 26;

const int encoderA = 52;
const int encoderB = 50;


void setup() {
  // put your setup code here, to run once:
  pinMode(enaneg,OUTPUT);
  pinMode(dirneg,OUTPUT);
  pinMode(pulneg,OUTPUT);

  pinMode(encoderA,INPUT);
  pinMode(encoderB,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x = 0; x < 200; x++) {
    digitalWrite(pulneg,HIGH);
    delayMicroseconds(500); 
//    Serial.println(digitalRead(encoderA));
//    Serial.println(digitalRead(encoderB));
    digitalWrite(pulneg,LOW);

    
//    Serial.println(digitalRead(encoderA));
//    Serial.println(digitalRead(encoderB));
    delayMicroseconds(500);
//    Serial.println("Pulse over");
//    Serial.println(digitalRead(encoderA));
//    Serial.println(digitalRead(encoderB));
   }
  delay(1000); // One second delay
}
