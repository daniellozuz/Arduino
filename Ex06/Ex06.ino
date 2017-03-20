void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i<999; i++){
    Serial.println(i);
    delay(1000);
  }
}

// Pamietac o 8 bit/chara
