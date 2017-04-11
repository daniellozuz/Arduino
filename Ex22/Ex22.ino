// Daniel Zuziak 10.04.17

#define TRIG 2
#define ECHO 3

int t;

void setup() {
  Serial.begin(9600);
  
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  t = pulseIn(ECHO, HIGH);
  Serial.println(t / 58);
  
  delay(50);
}
