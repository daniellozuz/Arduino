// Daniel Zuziak 4.04.17

#define TIME 5000
#define PWM 9

int duty;

void setup() {

}

void loop() {
  duty = 20;
  analogWrite(PWM, 255 * duty / 100);
  delay(TIME);
  
  duty = 50;
  analogWrite(PWM, 255 * duty / 100);
  delay(TIME);

  duty = 80;
  analogWrite(PWM, 255 * duty / 100);
  delay(TIME);
}
