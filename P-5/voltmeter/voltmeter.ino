#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int input=A0;
float r1=3702000.00;
float r2=18000.00;
void setup()
{
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  
}
void loop()
{
  int nomap=analogRead(input);
  float temp=(nomap*4.99)/1023;
  float volt=temp*(r1/(r1+r2));
  if(volt<0.1){
    volt=0.00;
  }
  lcd.setCursor(0,0);
  lcd.print("voltage");
  lcd.setCursor(0,1);
  lcd.print(volt);
  Serial.println(volt);
  delay(100);
}


