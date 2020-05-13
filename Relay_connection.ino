int R1 = 3;

void setup()
{
 Serial.begin(9600);
 pinMode(R1,OUTPUT);
}

void loop() 
{
  String bulb=Serial.readString();
 if(bulb=="ON")
  {
    digitalWrite(R1,0);
  }
 else if (bulb=="OFF")
  {
    digitalWrite(R1,1);
  } 

}
