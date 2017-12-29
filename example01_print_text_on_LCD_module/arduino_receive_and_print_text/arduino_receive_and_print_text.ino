// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 0x27 is the i2c address of the LCM1602 IIC v1 module (might differ)

void setup() {
  lcd.begin(16, 2); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight
  lcd.clear(); 

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }

  lcd.setCursor(0, 0); // set cursor to first row
  lcd.print("Init done"); // print to lcd
 
}

void loop() {
  if (Serial.available() > 0) {    
    byte incomingByte = 0;
    incomingByte = Serial.read(); // read the incoming byte:
    if (incomingByte != -1) { // -1 means no data is available
      lcd.setCursor(0, 0); // set cursor to first row
      lcd.print("I received: "); // print out to LCD
      lcd.setCursor(0, 1); // set cursor to secon row
      lcd.print(incomingByte); // print out the retrieved value to the second row
    }
  }
}
