String loc = "";

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);

  Serial.println("Initializing...");
  delay(1000);
}

void loop()
{
  updateSerial();
}

void updateSerial()
{
  loc = "-7.77284;110.34594";
  Serial1.println(loc);
  Serial.println(loc);
  delay(3000);
  while (Serial.available()) 
  {
    Serial1.write(Serial.read());
  }
  while(Serial1.available()) 
  {
    Serial.write(Serial1.read());
  }
}
