#include <AFMotor.h>
 AF_DCMotor motor1(1,MOTOR12_1KHZ);
 AF_DCMotor motor2(2,MOTOR12_1KHZ);
 AF_DCMotor motor3(3,MOTOR34_1KHZ);
 AF_DCMotor motor4(4,MOTOR34_1KHZ);


         boolean goesForward=false;
           int speedSet = 0;

            int X = A0;
             int Y = A1;
              int button =2;
               const int trig = 3;
                const int echo = 4;
                 int led = 5;


void setup() {
pinMode(X, INPUT);
  pinMode(Y,INPUT);
   pinMode(button, INPUT);
    pinMode(trig, OUTPUT);
     pinMode(echo, INPUT);
      pinMode(led, OUTPUT);
      motor1.setSpeed(230);
           motor2.setSpeed(230);
            motor3.setSpeed(230);
             motor4.setSpeed(230);
        Serial.begin(9600);

}

void loop() {
unsigned long duration;
   int button = digitalRead(button);
    int distance = (duration/2/29.412);
     int x = analogRead(X);
      int y = analogRead(Y);


        duration = pulseIn(echo,HIGH);
         digitalWrite(trig,LOW);
          delay(5);
           digitalWrite(trig,HIGH);
            delay(5);
             digitalWrite(trig, LOW);
              
  if (button = 1) {
   digitalWrite(led, HIGH);
    delay(5000);
     digitalWrite(led, LOW);
    
       }

         if (distance < 10) {
          digitalWrite(led,HIGH);
           }
            else {
             digitalWrite(led,LOW);
              }

                if (1022 <= X <= 1023) {
       motor1.run(FORWARD);      
        motor2.run(FORWARD);
         motor3.run(FORWARD); 
          motor4.run(FORWARD);   
                  }
                   else {

   motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);
                     }

                       if (X = 0) {
       motor1.run(BACKWARD);      
        motor2.run(BACKWARD);
         motor3.run(BACKWARD); 
          motor4.run(BACKWARD);    
                         }
                          else {
   motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);
                            }

                              if (1022 <= Y <= 1023) {
       motor1.run(BACKWARD);      
        motor2.run(FORWARD);
         motor3.run(FORWARD); 
          motor4.run(BACKWARD);
                                }
                                 else {
                                   }
   motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);
                                     if (Y = 0) {
       motor1.run(FORWARD);      
        motor2.run(BACKWARD);
         motor3.run(BACKWARD); 
          motor4.run(FORWARD);         
                                       }
                                        else {
   motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);            
                                          }
                                           
}
 
