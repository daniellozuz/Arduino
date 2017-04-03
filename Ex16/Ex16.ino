#include <LiquidCrystal.h>
#define delayTime 300

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte pac_open[8] = {
  B00000,
  B00000,
  B01110,
  B11100,
  B11000,
  B11100,
  B01110,
  B00000
};

byte pac_close[8] = {
  B00000,
  B00000,
  B01110,
  B11101,
  B11111,
  B11111,
  B01110,
  B00000
};

byte zero[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

int col = 0;
int row = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, pac_open);
  lcd.createChar(1, pac_close);
  lcd.createChar(2, zero);
  lcd.setCursor(5, 0);
  lcd.print("Daniel");
  lcd.setCursor(5, 1);
  lcd.print("Zuziak");
}

void loop() {
  if (col == 16)
    row += 1;
  col %= 16;
  row %= 2;
  lcd.setCursor(col, row);
  lcd.write(byte(1));
  delay(delayTime);
  lcd.setCursor(col, row);
  lcd.write(byte(2));
  lcd.setCursor(col, row);
  lcd.write(byte(0));
  delay(delayTime);
  lcd.setCursor(col, row);
  lcd.write(byte(2));
  col += 1;
}
