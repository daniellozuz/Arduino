#define OUT_PIN 13

int dir = -1;
int code[10] = {1,1,0,0,1,1,2,2,1,1}; // 0 - Góra; 1 - Prawo; 2 - Dół; 3 - Lewo; -1 - Nieokreślony
int sequence[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int st = 0; // Krok

bool compare(int t1[], int t2[], int k) {
  bool theSame = true;
  for (int i = 0; i <= k; i++) {
    if (t1[i] != t2[i])
      theSame = false;
  }
  return theSame;
}

void setup() {
  Serial.begin(9600);
  pinMode(OUT_PIN, OUTPUT);
}

void loop() {
  int sensorValueX = analogRead(A0);
  int sensorValueY = analogRead(A1);
  
  if (sensorValueX > 700) {
    dir = 1;
  }
  if ((sensorValueX <= 700) && (sensorValueX >= 300)) {
    dir = -1;
  }
  if (sensorValueX < 300) {   
    dir = 3;
  }
  if (sensorValueY > 700) {
    dir = 0;
  }
  if ((sensorValueY <= 700) && (sensorValueY >= 300)) {
    dir = -1;
  }
  if (sensorValueY < 300) {   
    dir = 2;
  }

  sequence[st] = dir;

  if (dir == -1 || !compare(sequence, code, st)) {
    st = 0;
    sequence = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  }
  else {
    st++;
  }
  
  delay(1000);
}
