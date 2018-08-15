bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;
int LastTime=0; 
#define UpperThreshold 550
#define LowerThreshold 500
int led=13;
int pressure=A0;
int heart=A1;
int voice=4;
int gsm=8;
int tazer=5;
int belt=3;
int a=0;
int b=0;
int c=0;
void setup() {
pinMode(pressure,INPUT);// put your setup code here, to run once:
pinMode(heart,INPUT);
pinMode(belt,INPUT);
pinMode(voice,OUTPUT);
pinMode(gsm,OUTPUT);
pinMode(tazer,OUTPUT);
Serial.begin(9600);
}

void loop() {

    int value=analogRead(heart);
   // Serial.println(value);
  if(value>UpperThreshold)
  {
    digitalWrite(led,HIGH);
    if(BeatComplete)
    {
      BPM=millis()-LastTime;
      BPM=int(60/(float(BPM)/1000));
      BPMTiming=false;
      BeatComplete=false;
    }
    if(BPMTiming==false)
    {
      LastTime=millis();
      BPMTiming=true;
    }
  }
  else
  {
    digitalWrite(led,LOW);
  }
 
  if((value<LowerThreshold)&(BPMTiming))
    {
      BeatComplete=true;
    }
Serial.println(analogRead(pressure));
  //  Serial.println(BPM);
if(analogRead(pressure)>450){
  
  a=a+1;
 }
 if(BPM>123)
 {
  b=b+1;
 }
 if(digitalRead(belt)==LOW)
 {
  c=c+1;
 }
 if(a==0 && b==0 && c==0)
 {
  digitalWrite(voice,LOW);
  digitalWrite(gsm,LOW);
  digitalWrite(tazer,LOW);
 }
 else if(a==0 && b!=0 && c==0)
 {
   digitalWrite(voice,LOW);
  digitalWrite(gsm,LOW);
  digitalWrite(tazer,LOW);
 }
 else if(a==0 && b==0 && c!=0)
 {
   digitalWrite(voice,LOW);
  digitalWrite(gsm,LOW);
  digitalWrite(tazer,LOW);
 }
 else
 {
   digitalWrite(voice,HIGH);
  digitalWrite(gsm,HIGH);
  digitalWrite(tazer,HIGH);
  
 }
 
}
