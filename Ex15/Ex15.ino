#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("Daniel");
  lcd.setCursor(5, 1);
  lcd.print("Zuziak");
}
