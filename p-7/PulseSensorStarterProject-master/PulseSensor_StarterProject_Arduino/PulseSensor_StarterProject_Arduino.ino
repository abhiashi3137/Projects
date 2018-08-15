bool BPMTiming=false;
bool BeatComplete=false;
int BPM=0;
int LastTime=0; 
#define UpperThreshold 550
#define LowerThreshold 500


void setup()
{
  Serial.begin(9600);
  
}


void loop(){
  int value=analogRead(0);
  Serial.println(value);
  if(value>UpperThreshold)
  {
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
  if((value<LowerThreshold)&(BPMTiming))
    BeatComplete=true;
    Serial.print(BPM);
}
