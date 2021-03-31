#include <AFMotor.h>
#include <Servo.h>
#include <Joystick.h>

#define ULTRA_CONST 29.412

const int button = 2;
const int trig = 22;
const int echo = 23;
const int led = 25;
const int distance_limit = 20;

const int X0 = 510;
const int Y0 = 484;
const int D = 13;

Servo servo_1;
Servo servo_2;
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Joystick joystick(A2, A0, 2);

boolean goesForward = false;
int speedSet = 0;
bool cam_lui = false;

int x, y; //Toa do JS
int xpin = A0; //gia tri can bang x
int ypin = A2; //gia tri can bang y
int speed_x, speed_y;
int xx, yy;
bool button_click = false;
unsigned long duration;
int distance;

void setup() {
	pinMode(A0, INPUT);
	pinMode(A2, INPUT);
	pinMode(button, INPUT);
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	pinMode(led, OUTPUT);
	motor1.setSpeed(150);
	motor2.setSpeed(150);
	motor3.setSpeed(150);
	motor4.setSpeed(150);
	Serial.begin(9600);
	digitalWrite(trig, LOW);

	int button = digitalRead(button);
	servo_1.attach(10);
	servo_1.attach(9);
}

void loop() {
	digitalWrite(trig, 0);
	delayMicroseconds(2);
	digitalWrite(trig, 1);
	delayMicroseconds(5);
	digitalWrite(trig, 0);
	duration = pulseIn(echo, HIGH);
	distance = int(duration / 2 / ULTRA_CONST);
	if (distance < distance_limit) {
		digitalWrite(led, HIGH);
		delay(100);
		if (!cam_lui) {
			xeStop();
			cam_lui = true;
		}
	} else {
		digitalWrite(led, LOW);
		cam_lui = false;
	}

	x = joystick.getx();
	y = joystick.gety();
	joystick.getz();
	if (joystick.z) {
		servo_1.writeMicroseconds(1500);
		delay(1000);
	}

	xx = (x - X0) / 2;
	speed_x = abs(xx);
	yy = (y - Y0) / 2;
	speed_y = abs(yy);
	if (speed_x > 255)
		speed_x = 255;
	if (speed_y > 255)
		speed_y = 255;

	if (yy > D) {
		if (xx > D) {
			upRightAtSpeed(speed_y);
		} else if (xx < -D) {
			upLeftAtSpeed(speed_y);
		} else {
			upAtSpeed(speed_y);
		}
	} else if (yy < -D) {
		if (!cam_lui) {
			if (xx > D) {
				downRightAtSpeed(speed_y);
			} else if (xx < -D) {
				downLeftAtSpeed(speed_y);
			} else {
				downAtSpeed(speed_y);
			}
		}
	} else {
		xeStop();
	}

	if (button == HIGH) {
		bat_o();
	} else {
		tat_o();
	}
}
void lmao() {
	unsigned long duration;
	digitalWrite(trig, LOW);
	delay(5);
	digitalWrite(trig, HIGH);
	delay(5);
	digitalWrite(trig, LOW);
	duration = pulseIn(echo, HIGH);
	int distance = (duration / 2 / 29.412);
	if (distance <= 10) {
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		delay(500);
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		delay(500);
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		motor1.run(RELEASE);
		motor2.run(RELEASE);
		motor3.run(RELEASE);
		motor4.run(RELEASE);

	} else {
		digitalWrite(led, LOW);
	}

}

void upAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_R(speed);
	setSpeed_L(speed);
	forward();
}

void downAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_R(speed);
	setSpeed_L(speed);
	backward();
}

void upLeftAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_L(speed);
	upLeft();
}

void upRightAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_R(speed);
	upRight();
}

void downLeftAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_L(speed);
	downLeft();
}

void downRightAtSpeed(uint8_t speed) {
	xeStop();
	setSpeed_R(speed);
	downRight();
}

void setSpeed_R(uint8_t speed) {
	motor1.setSpeed(speed);
	motor2.setSpeed(speed);
}

void setSpeed_L(uint8_t speed) {
	motor3.setSpeed(speed);
	motor4.setSpeed(speed);
}

void forward() {
	motor1.run(FORWARD);
	motor2.run(FORWARD);
	motor3.run(FORWARD);
	motor4.run(FORWARD);
}

void backward() {
	motor1.run(BACKWARD);
	motor2.run(BACKWARD);
	motor3.run(BACKWARD);
	motor4.run(BACKWARD);
}

void upLeft() {
	motor1.run(RELEASE);
	motor2.run(RELEASE);
	motor3.run(FORWARD);
	motor4.run(FORWARD);
}

void upRight() {
	motor1.run(FORWARD);
	motor2.run(FORWARD);
	motor3.run(RELEASE);
	motor4.run(RELEASE);
}

void downLeft() {
	motor1.run(RELEASE);
	motor2.run(RELEASE);
	motor3.run(BACKWARD);
	motor4.run(BACKWARD);
}

void downRight() {
	motor1.run(BACKWARD);
	motor2.run(BACKWARD);
	motor3.run(RELEASE);
	motor4.run(RELEASE);
}

void xeStop() {
	motor1.run(RELEASE);
	motor2.run(RELEASE);
	motor3.run(RELEASE);
	motor4.run(RELEASE);
}

void bat_o() {

}

void tat_o() {

}
