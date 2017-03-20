char incomingChar = '0';
int cnt = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        incomingChar = Serial.read();
        cnt++;
    }
    //Serial.print("Litera to: ");
    Serial.print(incomingChar);
    Serial.print(",");
    Serial.println(cnt);
    //Serial.println(" razy.");
    delay(1000);
}
// Przypomniec sobie jak robi sie stringi w C (tablice)
