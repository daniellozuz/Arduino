#define OUT_PIN 13

void setup() {
  Serial.begin(9600);
  pinMode(OUT_PIN, OUTPUT);
}

int decyzjaX = 0;
int decyzjaY = 0;
int stan = 0;
int nowy = 1;

void loop() {
  int sensorValueX = analogRead(A0);
  int sensorValueY = analogRead(A1);
  Serial.println(stan);
  delay(1000);
  if (sensorValueX > 700) {
    decyzjaX = 1;
  }
  if ((sensorValueX < 700) && (sensorValueX > 300)) {
    decyzjaX = 0;
  }
  if (sensorValueX < 300) {   
    decyzjaX = -1;
  }
  if (sensorValueY > 700) {
    decyzjaY = 1;
  }
  if ((sensorValueY < 700) && (sensorValueY > 300)) {
    decyzjaY = 0;
  }
  if (sensorValueY < 300) {   
    decyzjaY = -1;
  }

  switch (stan) {
    case 0:
      if (decyzjaX == 1)
        stan = 1;
      else
        stan = 0;
      break;
    case 1:
      if (decyzjaX == 1)
        stan = 2;
      else
        stan = 0;
      break;
    case 2:
      if (decyzjaY == 1)
        stan = 3;
      else
        stan = 0;
      break;
    case 3:
      if (decyzjaY == 1)
        stan = 4;
      else
        stan = 0;
      break;
    case 4:
      if (decyzjaX == 1)
        stan = 5;
      else
        stan = 0;
      break;
    case 5:
      if (decyzjaX == 1)
        stan = 6;
      else
        stan = 0;
      break;
    case 6:
      if (decyzjaY == -1)
        stan = 7;
      else
        stan = 0;
      break;
    case 7:
      if (decyzjaY == -1)
        stan = 8;
      else
        stan = 0;
      break;
    case 8:
      if (decyzjaX == 1)
        stan = 9;
      else
        stan = 0;
      break;
    case 9:
      if (decyzjaX == 1) {
        stan = 0;
        // pipczenie
        digitalWrite(OUT_PIN, HIGH);
        delay(1000);
        digitalWrite(OUT_PIN, LOW);
      }
      else
        stan = 0;
      break;
    default:
      break;
  }
}

// lepiej zapamietac w tablicy, mniej kodu
