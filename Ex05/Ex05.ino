void setup() {
  Serial.begin(9600);
  Serial.println("Wlaczam sie");
  delay(4000);
}

void loop() {
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  Serial.println("Dzialam");
  delay(100);
}
