 #include <SoftwareSerial.h>
int sense=8;
SoftwareSerial mySerial(9, 10);

void setup()
{
  pinMode(sense,INPUT);
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  int a=digitalRead(sense);
  Serial.println(a);
  if(a==1)
  {
    SendMessage();
 delay(1500000);
  }

}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919550245406\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("king * SECRET E96940 *9849625888 ");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}



