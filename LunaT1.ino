#include <Servo.h>
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo servo1;

const int trigPin = 10;
const int echoPin = 7;

long duration;
int distance;
int left, right, front;

void setup() {

  pinMode(8,INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  servo1.attach(9);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}


void loop() {

  if (digitalRead(8)== LOW)
  {
   Serial.print("There is a hole...");
    delay(500);
  }
 
  sonor();              //measure the distance from front site
  if(distance<25)
  {
    ServoPos();
  }
  else
  {
    Serial.print("Obstacle Detected:\n");
  }

}


void sonor()
{
  digitalWrite(trigPin, LOW); //CLEARE THE TRIGPIN
  delayMicroseconds(2);//SET THE TRIGPIN ON HIGH STATE FOR 10 SECONDS

  digitalWrite(trigPin, HIGH); //WRITE THE TRIGGER FOR MCU ON MODULE
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //READS THE ECHOPIN, RETURNS THE SOUND WAVE TRAVEL TIME IN MICROSECONDS

  duration = pulseIn(echoPin, HIGH); //USING THE FORMULA
  distance = duration * 0.034 / 2;
  Serial.print("\nFront: ");
  Serial.println(distance);//PRINT THE DISTANCE ON THE SERIAL MONITOR

}

void ServoPos()
{
  int l,r,f;

  //left side
  for(l=90; l<=0; l--)
  {
     servo1.write(l);
     delay(33);
  }

  delay(500);
  sonor();
  left = distance;
  
  //right side
  for(r=0; r<=180; r++)
  {
     servo1.write(r);
     delay(33);
  }

  delay(500);
  sonor();
  right = distance;

  

  for(f=180; f<=90; f--)
  {
     servo1.write(j);
     delay(33);
  }

  delay(500);
  sonor();
  front = distance;

}
