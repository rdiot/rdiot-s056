/* XY-axis Joystick Module (KY-023) [S056] : http://rdiot.tistory.com/136 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
 
int X = A0; // x
int Y = A1; // y
int S = 2; // SW
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(S, INPUT);
  digitalWrite(S, HIGH); 
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S056:XY-axis Joystick");
 
  int x, y, s; 
  x = analogRead(X);
  y = analogRead(Y);
  s = digitalRead(S);
 
  lcd.setCursor(0,1);
  lcd.print("X=" + (String)x + "   ");
 
  lcd.setCursor(0,2);
  lcd.print("Y=" + (String)y + "   ");
 
  lcd.setCursor(0,3);
  lcd.print("SW=" + (String)s + "  ");
 
  delay(100);
}
