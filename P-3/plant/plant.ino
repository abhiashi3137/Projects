#include<Servo.h>
#include"DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int sensor=A0;
Servo myservo;
int pos=0;
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(sensor,INPUT);
  dht.begin();
}
void loop()
{
 int sensorvalue=analogRead(sensor);
 int percentage=map(sensorvalue,1023,450,0,100);
 delay(1000);
 Serial.print("moisture");
 Serial.print(percentage);
 Serial.print("%\t");
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
float hif = dht.computeHeatIndex(f, h);  
float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  if(percentage<=15)
  {
    pos=45;
    myservo.write(pos);
  }
  if(percentage>30)
  {pos=135;
  myservo.write(pos);
  
}
}
