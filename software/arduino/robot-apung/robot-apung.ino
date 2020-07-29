#include <Wire.h>
#include <HMC5883L.h>
#include <TinyGPS++.h>

String cmd = "";
String cmds = "";
String latWaypoint[5] = {
  "",
  "",
  "",
  "",
  ""
};
String longWaypoint[5] = {
  "",
  "",
  "",
  "",
  ""
};
int countWaypoint = 0;
int countUpdateGPS = 0;
int goStatus = 0;

TinyGPSPlus gps;
HMC5883L compass;

void setup() {
  Serial.begin(115200); // to PC
  Serial1.begin(9600); // Telemetry
  Serial2.begin(9600); // GPS
  delay(100);

  Serial.println("Robot Apung");
  delay(250);

  /*Wire.begin(); // Compass
  compass.begin();
  compass.setRange(HMC5883L_RANGE_1_3GA);
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
  compass.setDataRate(HMC5883L_DATARATE_30HZ);
  compass.setSamples(HMC5883L_SAMPLES_8);
  compass.setOffset(0, 0);*/

  startup(); // Wait GPS Locked // startup
  setWaypoint(); // Set 5 Waypoints // setwaypoint
}

void loop() {
  if (countUpdateGPS >= 10) {
    updateGPS(); // gps
    countUpdateGPS = 0;
  }
  cmds = checkCommand();
  cmd = cmds.substring(0, 3);
  if (cmd != "") {
    if (cmd == "GOO") {
      Serial.println("Command: GOO");
      Serial.println("Run Waypoint");
      goStatus = 1;
      go();
    }
    cmd = "";
  }
  delay(500);
  countUpdateGPS += 1;
}
