
#include <LiquidCrystal.h>
int ledPin=6;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  int state1=digitalRead(ledPin);
  delay(30);
  int state2=digitalRead(ledPin);
  Serial.println("state1");
  Serial.println(state1);
  Serial.println("state2");
  Serial.println(state2);
  if(state1==state2)
  {
  
  lcd.print("Notworking");
}
else
{
  lcd.print("working");
}
}
void loop(){
}

