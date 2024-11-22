//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a,b,c;
int f = 1;
int depth=14 ;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop()
{
  if ( f == 1 ) {
    a=sr04.Distance();
    b = a ;
    c = a ;
    f = 0 ;
  } else {
    c = b;
    b = a ;
    a=sr04.Distance();
  }

  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Reservoir ");
  lcd.print(depth - (a+b+c)/(3*2.54));        // print message at (0, 0)
  lcd.print("\"");        // print message at (0, 0)
  lcd.setCursor(1, 1);         // move cursor to   (2, 1)
  lcd.print("min 3\" max 11\""); // print message at (2, 1)
  delay(4000);                 // display the above for two seconds

}
