#include <AFMotor.h>
 AF_DCMotor motor1(1,MOTOR12_1KHZ);
 AF_DCMotor motor2(2,MOTOR12_1KHZ);
 AF_DCMotor motor3(3,MOTOR34_1KHZ);
 AF_DCMotor motor4(4,MOTOR34_1KHZ);


         boolean goesForward=false;
           int speedSet = 0;
            int X = A0;
             int Y = A2;
              int button =2;
               const int trig = 3;
                const int echo = 4;
                 int led = 5;


void setup() {
pinMode(A0, INPUT);
  pinMode(A2,INPUT);
   pinMode(button, INPUT);
    pinMode(trig, OUTPUT);
     pinMode(echo, INPUT);
      pinMode(led, OUTPUT);
      motor1.setSpeed(230);
           motor2.setSpeed(230);
            motor3.setSpeed(230);
             motor4.setSpeed(230);
        Serial.begin(9600);

         int button = digitalRead(button);


}

void loop() {
        int x = analogRead(X);
      int y = analogRead(Y);

     

 void lmao () ;
       
 
                if (x >1021) {
       motor1.run(FORWARD),
        motor2.run(FORWARD),
         motor3.run(FORWARD), 
          motor4.run(FORWARD);   

                  }
                   else {

   motor1.run(RELEASE),
    motor2.run(RELEASE),
     motor3.run(RELEASE),
      motor4.run(RELEASE);
                     }

                       if (X = 0) {
       motor1.run(BACKWARD),     
        motor2.run(BACKWARD),
         motor3.run(BACKWARD),
          motor4.run(BACKWARD);    
          delay(1000);
                         }
                          else {
   motor1.run(RELEASE),
    motor2.run(RELEASE),
     motor3.run(RELEASE),
      motor4.run(RELEASE);
                            }

                              if (y >1021) {
       motor1.run(BACKWARD),      
        motor2.run(FORWARD),
         motor3.run(FORWARD), 
          motor4.run(BACKWARD);
          delay(1000);
                                }
                                 else {
                                   }
   motor1.run(RELEASE),
    motor2.run(RELEASE),
     motor3.run(RELEASE),
      motor4.run(RELEASE);
                                     if (Y = 0) {
       motor1.run(FORWARD),      
        motor2.run(BACKWARD),
         motor3.run(BACKWARD), 
          motor4.run(FORWARD);     
          delay(1000);    
                                       }
                                        else {
   motor1.run(RELEASE),
    motor2.run(RELEASE),
     motor3.run(RELEASE),
      motor4.run(RELEASE);            
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

    
}
