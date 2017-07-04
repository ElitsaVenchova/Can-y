#include <Servo.h>
#include <secTimer.h>
#define SERVO_PIN 0                        //pin for servo motor
Servo Gripper;                              //servo for gripper


//L293D
//Motor A
const int motorPinA1  = A1;  // Pin 14 of L293
const int motorPinA2  = A2;  // Pin 10 of L293
//Motor B
const int motorPinB1  = A3; // Pin  7 of L2931
const int motorPinB2  = A4;  // Pin  2 of L293
int i;
int val;
int redpin = A0;
secTimer myTimer;
unsigned long seconds;

boolean caughtObject = false;

void setup() {
  //Set pins as outputs
  pinMode(redpin, OUTPUT);
  Serial.begin(1200);
  myTimer.startTimer();


}


void loop() {

  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
  pinMode(motorPinB1, OUTPUT);
  pinMode(motorPinB2, OUTPUT);

  int checkVal = checkForObject();
  if (checkVal == 0) {
    seconds = myTimer.readTimer();
    Serial.println(seconds);
    openGripper();
    halt();
    delay(500);
    forward();
    delay(250);
    closeGripper();
    halt();
    backwards();
    if ( seconds > 1) {
      delay(1000);
    }
    left();
    delay(550);
    halt();
    forward();
    Serial.println(seconds);
    if ( seconds < 1) seconds = 1;
    delay(seconds * 1000  - 500);
    halt();
    openGripper();
    backwards();
    delay(200);
    for (int j = 0; j < 3; j++) {
      openGripper();
      delay(200);
      closeGripper();
      delay(200);
    }
    //    delay(3000);
    //    backwards();
    delay(500);
    left();
    delay(200);
    //    closeGripper();
    myTimer.startTimer();

  } else {
    forward();

  }

}

int checkForObject() {
  pinMode(redpin, INPUT);
  i = digitalRead(redpin);
  return i;
  // prints the value of the sensor to the serial monitor
  Serial.println(val);
}

void stopAndOpen() {
  halt();
  openGripper();
}

void stopAndClose() {
  halt();
  closeGripper();
}

void openGripper() {
  halt();
  Serial.println("open");
  Gripper.attach(SERVO_PIN);
  Gripper.write(0); //open Gripper
  delay(500);
  Gripper.detach();

}

void closeGripper() {
  halt();
  Serial.println("close");
  Gripper.attach(SERVO_PIN);
  Gripper.write(110); //close Gripper
  Serial.println("test1");
  delay(500);
  Serial.println("test");
  Gripper.detach();
}

void forward() {
  //  halt();
  //  digitalWrite(motorPinB2, LOW);
  //  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
  digitalWrite(motorPinA2, HIGH);
  Serial.println("forward");
}
void right() {
  halt();
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA2, HIGH);
  digitalWrite(motorPinB1, HIGH);
  Serial.println("right");

}
void left() {
  halt();
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB1, LOW);
  digitalWrite(motorPinB2, HIGH);
  digitalWrite(motorPinA1, HIGH);
  Serial.println("left");
}
void backwards() {
  halt();
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA1, HIGH);
  digitalWrite(motorPinB1, HIGH);
  Serial.println("backwards");
}
void halt() {
  digitalWrite(motorPinA2, LOW);
  digitalWrite(motorPinB2, LOW);
  digitalWrite(motorPinA1, LOW);
  digitalWrite(motorPinB1, LOW);
  delay(200);
  Serial.println("stop");

}
