#define OUT_PIN 13
#define DIR_UP 'U'
#define DIR_DOWN 'D'
#define DIR_RIGHT 'R'
#define DIR_LEFT 'L'
#define DIR_NONE 'O'
#define H_TRESHOLD 700
#define L_TRESHOLD 200

char dir = DIR_NONE;
char code[10] = {DIR_RIGHT, DIR_RIGHT, DIR_UP, DIR_UP, DIR_RIGHT, DIR_RIGHT, DIR_DOWN, DIR_DOWN, DIR_RIGHT, DIR_RIGHT};
char sequence[10] = {DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE, DIR_NONE};
int st = 0;
bool neutral = true;

bool compare(char t1[], char t2[], int k) {
  bool theSame = true;
  for (int i = 0; i <= k; i++) {
    if (t1[i] != t2[i]) {
      theSame = false;
    }
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
  
  if (sensorValueX > H_TRESHOLD && neutral) {
    dir = DIR_LEFT;
    neutral = false;
  }
  if (sensorValueX < L_TRESHOLD && neutral) {   
    dir = DIR_RIGHT;
    neutral = false;
  }
  
  if (sensorValueY > H_TRESHOLD && neutral) {
    dir = DIR_UP;
    neutral = false;
  }
  if (sensorValueY < L_TRESHOLD && neutral) {   
    dir = DIR_DOWN;
    neutral = false;
  }

  if (((sensorValueX <= H_TRESHOLD) && (sensorValueX >= L_TRESHOLD)) && ((sensorValueY <= H_TRESHOLD) && (sensorValueY >= L_TRESHOLD))) {
    neutral = true;
  }

  if (dir != DIR_NONE && neutral == false)
  {
    sequence[st] = dir;
    dir = DIR_NONE;
    for (int i = 0; i < 9; i++) {
      Serial.print(sequence[i]);
    }
    Serial.println(sequence[9]);

    if (!compare(sequence, code, st) || st == 10) {
      Serial.println("Error");
      st = 0;
      for (int i = 0; i < 10; i++) {
        sequence[i] = DIR_NONE;
      }
    }
    else {
      st++;
    }
  }

  if (st == 10) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    st = 0;
  }
}

