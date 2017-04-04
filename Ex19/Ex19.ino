// Daniel Zuziak 4.04.17

#define TIME 5000
#define PWM 9

float duty;
int sensorValueX;

void setup() {

}

void loop() {
  sensorValueX = analogRead(A0);

  if (sensorValueX > 700)
    duty = 75;
  else if (sensorValueX < 300)
    duty = 25;
  else
    duty = 50;
  
  analogWrite(PWM, (float)255 * duty / 100);
}

