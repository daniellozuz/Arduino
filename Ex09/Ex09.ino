void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int decyzja = 0;
  
void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > 700) {
    decyzja = 1;
  }
  if (sensorValue < 300) {   
    decyzja = 0;
  }
  if (decyzja)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);
  delay(1);
}
