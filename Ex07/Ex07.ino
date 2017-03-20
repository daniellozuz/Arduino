char incomingChar = '0';

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
    incomingChar = Serial.read();
  Serial.print("Litera to: ");
  Serial.println(incomingChar);
  delay(1000);
}

// Pamietac o 8 bit/chara
