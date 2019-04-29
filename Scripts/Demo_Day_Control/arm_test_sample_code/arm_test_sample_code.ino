
# include <Servo.h>
Servo servo;
Servo servo2;
int servopin = 9;
int uparmpin = 10;
int pos;
float posread;
float scale;
float offset;
float maxrange;
float goal;
float cmd;
float error;
float propterm;
float kp;
float intterm;
float ki;
float inttermpast = 0;
int count=0;
int countuparm = 0;
float readval = 0;

   char command[6];
   String info;
   int angle;

void setup() {
  // put your setup code here, to run once:
  servo.attach(servopin);
  servo2.attach(uparmpin);
  Serial.begin(9600);
  servo.write(130);
   pinMode(7,OUTPUT);
//  servo.write(90);
  pos = 90;
  scale = 440-70;
  offset = 0;
  maxrange = 180;
  ki = .3;
  kp = 5;
  goal = 220;
  inttermpast = 0;
}

void loop() {

  // put your main code here, to run repeatedly:
   if(Serial.available() > 0)
    {
     info = Serial.readStringUntil('E');
      
    }
    
      info.toCharArray(command, 6);
      if(command[1] == '1') {
          if(command[2] == 'D') {
            angle = info.substring(3).toInt();
            servo.write(angle);
          }
      }
     else if(command[1] == '2') {
        if(command[2] == 'D'){
            angle = info.substring(3).toInt();
            if(angle==180){
              digitalWrite(7,HIGH);
            }
            else if(angle==80){
             digitalWrite(7,LOW); 
            }
            servo2.write(angle);
          }
     }
     /*
  servo2.write(130);
  servo.write(120);
  servo2.write(80);
  delay(1000);
  servo.write(130);
  delay(1000);
  servo.write(180);
  servo2.write(80);
  delay(1000);
  servo2.write(130);
  delay(1000); */
  }
