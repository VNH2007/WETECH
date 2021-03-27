#include <AFMotor.h>
 AF_DCMotor motor1(1,MOTOR12_1KHZ);
 AF_DCMotor motor2(2,MOTOR12_1KHZ);
 AF_DCMotor motor3(3,MOTOR34_1KHZ);
 AF_DCMotor motor4(4,MOTOR34_1KHZ);


         boolean goesForward=false;
           int speedSet = 0;

            int x = A0;
             int y = A1;
              int button =2;
               const int trig = 3;
                const int echo = 4;
                 int led = 5;


void setup() {
pinMode(x, INPUT);
  pinMode(y,INPUT);
   pinMode(button, INPUT);
    pinMode(trig, OUTPUT);
     pinMode(echo, INPUT);
      pinMode(led, OUTPUT);
        Serial.begin(9600);

}

void loop() {
unsigned long duration;
   int button = digitalRead(button);
    int distance = (duration/2/29.412);
     int x = analogRead(x);
      int y = analogRead(y);


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

                if (y > 1) {
                 moveForward ();
                  }
                   else {
                    moveStop ();
                     }

                       if (y < -1) {
                        moveBackward ();
                         }
                          else {
                           moveStop ();
                            }

                              if (x > 1) {
                               turnRight ();
                                }
                                 else {
                                  moveStop ();
                                   }

                                     if (x < -1) {
                                      turnLeft ();
                                       }
                                        else {
                                         moveStop ();
                                          }
                                           
}
  void moveStop() {

   motor1.run(RELEASE); 
    motor2.run(RELEASE);
     motor3.run(RELEASE);
      motor4.run(RELEASE);
       } 
  
  void moveForward() {

    if(!goesForward)
     {
      goesForward=true;
       motor1.run(FORWARD);      
        motor2.run(FORWARD);
         motor3.run(FORWARD); 
          motor4.run(FORWARD);     
           for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
            {
             motor1.setSpeed(speedSet);
              motor2.setSpeed(speedSet);
               motor3.setSpeed(speedSet);
                motor4.setSpeed(speedSet);
                 delay(5);
                  }
                   }
                    }
 
  void moveBackward() {

   goesForward=false;
    motor1.run(BACKWARD);      
     motor2.run(BACKWARD);
      motor3.run(BACKWARD);
       motor4.run(BACKWARD);  
        for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2)
         {
          motor1.setSpeed(speedSet);
           motor2.setSpeed(speedSet);
            motor3.setSpeed(speedSet);
             motor4.setSpeed(speedSet);
              delay(5);
               }
                }  

  void turnRight() {

   motor1.run(FORWARD);
    motor2.run(FORWARD);
     motor3.run(BACKWARD);
      motor4.run(BACKWARD);     
       delay(300);
        motor1.run(FORWARD);      
         motor2.run(FORWARD);
          motor3.run(FORWARD);
           motor4.run(FORWARD);      
            } 
 
  void turnLeft() {

motor1.run(BACKWARD);    
motor2.run(BACKWARD);  
motor3.run(FORWARD);
motor4.run(FORWARD);   
delay(300);
motor1.run(FORWARD);     
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
}  
