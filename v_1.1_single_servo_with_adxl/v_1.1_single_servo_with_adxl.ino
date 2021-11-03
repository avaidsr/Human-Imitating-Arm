#include <AFMotor.h>
#include<Servo.h>

Servo serv;

int xv=0;
int xm=0;
int yv=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serv.attach(9   );
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.println("START");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("x: ");
  xv=analogRead(A0);
  Serial.print(xv);
  
  xm=map(xv,270,400,180,0);
  if(xm>180)
  {
    xm=180;
  }
  else if(xm<0)
  {
    xm=0;
  }
  Serial.print("        ");
  Serial.println(xm);
  serv.write(xm);
  
//  Serial.print("y: ");
//  Serial.println(analogRead(A1));
  delay(100);
}
