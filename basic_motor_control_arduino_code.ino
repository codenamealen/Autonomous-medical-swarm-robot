char cmd;

void setup() {
  Serial.begin(9600);

  pinMode(6, OUTPUT); // ENA
  pinMode(7, OUTPUT); // IN1
  pinMode(8, OUTPUT); // IN2

  analogWrite(6, 255); // full speed
}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read();

    if (cmd == 'F') {          // Forward
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
    }
    else if (cmd == 'B') {     // Backward
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
    }
    else if (cmd == 'S') {     // Stop
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
    }
  }
}
