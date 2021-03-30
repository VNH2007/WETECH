#include <AFMotor.h>
 AF_DCMotor motor1(1,MOTOR12_1KHZ);
 AF_DCMotor motor2(2,MOTOR12_1KHZ);
 AF_DCMotor motor3(3,MOTOR34_1KHZ);
 AF_DCMotor motor4(4,MOTOR34_1KHZ);


         boolean goesForward=false;
           int speedSet = 0;
            int X = A0;
             int Y = A2;
        int x = analogRead(X);
      int y = analogRead(Y);

         int button = digitalRead(button);
              int button =2;
               const int trig = 3;
                const int echo = 4;
                 int led = 5;
const int D = 16;
const int y0 = 484;
const int x0 = 510;


void setup() {
pinMode(A0, INPUT);
  pinMode(A2,INPUT);
   pinMode(button, INPUT);
    pinMode(trig, OUTPUT);
     pinMode(echo, INPUT);
      pinMode(led, OUTPUT);
      motor1.setSpeed(0);
           motor2.setSpeed(0);
            motor3.setSpeed(0);
             motor4.setSpeed(0);
        Serial.begin(9600);



}

void loop() {
int x;
 int y;
 int button;
 lmao () ;
       
 
                if (y > y0 + D) {
  tien () ;   

                  }
                   else {
  dung () ;
                     }

                       if (y < y0 - D) {
  lui () ;
                         }
                          else {
  dung () ;
                            }

                              if (x > x0 + D) {
  phai () ;
                                }
                                 else {
  dung () ;                              
                                 }

                                     if (x < x0 - D) {
  trai () ;
                                       }
                                        else {
  dung () ;          
                                          }
                                           
}
void lmao () {
  unsigned long duration;
    digitalWrite(trig,LOW);
          delay(5);
           digitalWrite(trig,HIGH);
            delay(5);
             digitalWrite(trig, LOW);
        duration = pulseIn(echo,HIGH);
    int distance = (duration/2/29.412);
     if (distance <= 10) {
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
      motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);
    
  }
  else {
    digitalWrite(led,LOW);
  }
void tien () {
  motor1.setSpeed(y : 4);
  motor2.setSpeed(y : 4);
  motor3.setSpeed(y : 4);
  motor4.setSpeed(y : 4);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD); 
  motor4.run(FORWARD);  
}
 
 void lui () {
  motor1.setSpeed(y : 4);
  motor2.setSpeed(y : 4);
  motor3.setSpeed(y : 4);
  motor4.setSpeed(y : 4);
  motor1.run(BACKWARD);      
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
 }
 void trai () {
  motor1.setSpeed(x : 4);
  motor2.setSpeed(x : 4);
  motor3.setSpeed(x : 4);
  motor4.setSpeed(x : 4);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD); 
  motor4.run(RELEASE);  
 }
  void phai () {
  motor1.setSpeed(x : 4);
  motor2.setSpeed(x : 4);
  motor3.setSpeed(x : 4);
  motor4.setSpeed(x : 4);
  motor2.run(RELEASE);
  motor1.run(FORWARD);
  motor4.run(FORWARD); 
  motor3.run(RELEASE);  
 }
 
 void dung () {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE); 
  motor4.run(RELEASE);
