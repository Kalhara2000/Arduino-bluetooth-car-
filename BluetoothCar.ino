int x;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  analogWrite(11, 200);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  analogWrite(5, 200);

  Serial.begin(9600);  // Set data transfer speed
}

void loop() {
  // Check if data is available on the serial port
  while (Serial.available() > 0) {
    x = Serial.read();
    Serial.println(x);
    // Perform actions based on received data
    if (x == '1') {
      // Forward
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
    } else if (x == '2') {
      // Backward
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    } else if (x == '3') {
      // Turn right
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    } else if (x == '4') {
      // Turn left
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    } else {
      // Stop all motors
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
  }
}