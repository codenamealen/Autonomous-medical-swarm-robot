
// Motor driver pins
const int ENA = 5;   // Enable pin (PWM)
const int IN1 = 7;   // Direction pin 1
const int IN2 = 8;   // Direction pin 2

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void loop() {

  // Rotate motor FORWARD
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);   // Speed (0–255)

  delay(3000);  // Run for 3 seconds

  // Stop motor
  analogWrite(ENA, 0);
  delay(2000);

  // Rotate motor BACKWARD
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);

  delay(3000);

  // Stop motor
  analogWrite(ENA, 0);
  delay(2000);
}