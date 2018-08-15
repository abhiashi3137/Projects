#include <LiquidCrystal.h>
LiquidCrystal lcd(12 , 11, 5, 4, 3, 2);
int check;
int opamp=6;
int timer=8;
int Delay;
void setup() {
  Serial.begin(9600);
   lcd.begin(16, 2);
   if(digitalRead(opamp)==HIGH)
   {
    Delay=37;
    check=7;
   }
   if(digitalRead(timer)==HIGH)
   {
   check=9;
    Delay=30;  
   }
   Serial.print(check);
  int state1=digitalRead(check);
  delay(Delay);
  Serial.print(state1);
  int state2=digitalRead(check);
  Serial.print(state2);
  delay(Delay);

  if(state1==state2)
  {lcd.setCursor(5,0);
   lcd.print("Not working");
  }
  else
  {lcd.setCursor(5,0);
    lcd.print("Working");
  }
}

void loop() {
 
}

