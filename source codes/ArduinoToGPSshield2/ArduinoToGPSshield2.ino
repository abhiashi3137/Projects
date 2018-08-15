float test;

String inString = "";    

String firstVal, secondVal, thirdVal, forthVal, fifthVal, sixthVal, seventhVal, eighthVal;
   
void setup()
{
  Serial.begin(9600);
  Serial.println("Start listening for GPS Shield...");
}

void loop() 
{
  while (Serial.available() > 0) 
  {
    inString = Serial.readString();
      
    
    for (int i = 0; i < inString.length(); i++) 
    {
      if (inString.substring(i, i+1) == "*")
      {
        firstVal = inString.substring(1, i);
        secondVal = inString.substring(i+1);
        //Serial.println("Latitude: " + (firstVal) + ", second: " + (secondVal)); 
      }
    }

    for (int i = 0; i < secondVal.length(); i++) 
    {
      if (secondVal.substring(i, i+1) == "%")
      {
        thirdVal = secondVal.substring(0, i);
        forthVal = secondVal.substring(i+1);
        //Serial.println("Longitude: " + (thirdVal) + ", forth: " + (forthVal));    
      }
    }

    for (int i = 0; i < forthVal.length(); i++) 
    {
      if (forthVal.substring(i, i+1) == "@")
      {
        fifthVal = forthVal.substring(0, i);
        sixthVal = forthVal.substring(i+1);
        //Serial.println("Accuracy: " + (fifthVal) + ", sixth: " + (sixthVal));    
        //test = fifthVal.toFloat();
      }
    }

    for (int i = 0; i < sixthVal.length(); i++) 
    {
      if (sixthVal.substring(i, i+1) == "#")
      {
        seventhVal = sixthVal.substring(0, i);
        eighthVal = sixthVal.substring(i+1);
        //Serial.println("Time: " + (seventhVal) + ", eighth: " + (eighthVal));    
      }
    }
    
    Serial.println("Latitude: " + (firstVal) + ",    Longitude: " + (thirdVal) + ",    Accuracy: " + (fifthVal) + ",    Time: " + (seventhVal)); 
    //Serial.println(test, 5);
  }

}

