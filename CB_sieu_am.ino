const int trig = 3;
const int echo = 4;
int led = 5;

void setup() {
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(led,OUTPUT);

}

void loop() {
 unsigned long duration;
 digitalWrite(trig,LOW);
 delay(5);
 digitalWrite(trig,HIGH);
 delay(5);
 digitalWrite(trig,LOW);
  duration = pulseIn (echo,HIGH);
   int distance = (duration/2/29.412);

 if (distance <= 10) {
  digitalWrite(led,HIGH);
  delay(100);
  digitalWrite(led,LOW);
  }
  else {
    digitalWrite(led,LOW);
  }


}
