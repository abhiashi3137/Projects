void setup() {
 Serial.begin(9600);
 pinMode(13,OUTPUT);// put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0)
  {char data = Serial.read();
  switch(data)
  {
    case 'a' : digitalWrite(13,HIGH);
    case 'b' : digitalWrite(13,LOW);
  }
  Serial.println(data);
  }
  delay(50);
}
  
  // put your main code here, to run repeatedly:


