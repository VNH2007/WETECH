#define motorL  2
#define motorL2 3
#define motorR 4
#define motorR2 5
#define MAX_SPEED 255
#define MIN_SPEED -127.5
const int trigF = 1;
const int echoF = 2;

const int trigB = 3;
const int echoB = 4;

int led = 9;

void setup() {
    Serial.begin(9600); 

  pinMode(motorL, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(motorR, OUTPUT);
  pinMode(motorR2, OUTPUT);
  
  pinMode(trigF,OUTPUT);
  pinMode(echoF,INPUT);
  pinMode(trigB,OUTPUT);
  pinMode(echoB,INPUT);
  
  pinMode(straight, INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(back,INPUT);
  
  pinMode(led,OUTPUT);
