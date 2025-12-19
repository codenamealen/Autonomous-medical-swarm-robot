#include <Servo.h>

Servo servo1;

int trigPin = 9;
int echoPin = 8;

long duration;
int distance;

int servoState = 0;
/*
0 = waiting (center)
1 = moved right
2 = moved left
*/

void setup() {
  servo1.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.write(90);  // normal position
  delay(500);
}

void loop() {
  ultra();

  if (distance > 0 && distance <= 10) {

    // First detection → turn right
    if (servoState == 0) {
      servo1.write(180);
      servoState = 1;
      delay(800);
    }

    // Second detection → turn left
    else if (servoState == 1) {
      servo1.write(0);
      servoState = 2;
      delay(800);
    }

    // Detection finished → return to normal
    else if (servoState == 2) {
      servo1.write(90);
      servoState = 0;  // reset cycle
      delay(1000);
    }
  }
}

void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000); // timeout
  if (duration == 0) {
    distance = -1;
  } else {
    distance = duration * 0.034 / 2;
  }
}

