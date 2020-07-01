#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L_Simple.h>

HMC5883L_Simple Compass;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  Compass.SetDeclination(0, 49, 'E');
  Compass.SetSamplingMode(COMPASS_SINGLE);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_X_NORTH);
}

void loop()
{
  float heading = Compass.GetHeadingDegrees();

  Serial.print("Heading: \t");
  Serial.println(heading);
  delay(1000);
}
