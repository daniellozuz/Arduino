#include <LiquidCrystal.h>

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

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

byte one[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

int i;
int col = 0; 
int row = 0;
int level = 8;
unsigned long t;
unsigned long last_t = 0L;
unsigned long const DELTA = 1000L; 
int adc_key_in  = 0;

void showBars(int l);
int read_LCD_buttons();

void setup() {
  lcd.begin(16,2);

  lcd.createChar(0, zero);
  lcd.createChar(1, one);

  pinMode(2, INPUT);
}

void loop() {
  t = millis();

  if ((t - last_t) > DELTA) {
    // wczytaj buttony i zmien level
    read_LCD_buttons();
    
    if (adc_key_in == btnRIGHT)
      level++;
    if (adc_key_in == btnLEFT)
      level--;

    if (level > 16)
      level = 16;
    if (level < 0)
      level = 0;
      
    showBars(level);
    last_t = t;
  }
}

void showBars(int l) {
  // Gaszenie calosci
  for (i = 0; i < 17; i++) {
    lcd.setCursor(i,0);
    lcd.write(byte(0));
    lcd.setCursor(i,1);
    lcd.write(byte(0));
  }

  // Swiecenie tyle barow ile trzeba
  for (i = 0; i < l; i++) {
    lcd.setCursor(i,0);
    lcd.write(byte(1));
  }

  // Wyswietlanie liczby
  lcd.setCursor(0,1);
  lcd.print(l);
}

int read_LCD_buttons() {
  adc_key_in = analogRead(0);
  
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;  
  if (adc_key_in < 195)  return btnUP; 
  if (adc_key_in < 380)  return btnDOWN; 
  if (adc_key_in < 555)  return btnLEFT; 
  if (adc_key_in < 790)  return btnSELECT;   

  return btnNONE;
}

