#include <AFMotor.h>
#include<Servo.h>

Servo serv1,serv2;

int xv1=0;
int xm1=0;
int xv2=0;
int xm2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serv1.attach(10);
  serv2.attach(9);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.println("START");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("x1: ");
  xv1=analogRead(A0);
  Serial.print(xv1);
  
  xm1=map(xv1,270,400,180,0);
  if(xm1>180)
  {
    xm1=180;
  }
  else if(xm1<0)
  {
    xm1=0;
  }
  Serial.print("        ");
  Serial.print(xm1);
  serv1.write(xm1);

  //second accel and servo

   Serial.print("  ");
   Serial.print("x2: ");
  xv2=analogRead(A1);
  Serial.print(xv2);
  
  xm2=map(xv2,270,400,180,0);
  if(xm2>180)
  {
    xm2=180;
  }
  else if(xm2<0)
  {
    xm2=0;
  }
  Serial.print("        ");
  Serial.println(xm2);
  serv2.write(xm2);
  
//  Serial.print("y: ");
//  Serial.println(analogRead(A1));
  delay(100);
}
