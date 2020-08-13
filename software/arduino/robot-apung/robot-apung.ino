#include <Wire.h>
#include <HMC5883L.h>
#include <TinyGPS++.h>

int pwm1A = 2;
int in1A1 = 3;
int in1A2 = 4;
int pwm1B = 7;
int in1B1 = 5;
int in1B2 = 6;

int pwm2A = 8;
int in2A1 = 9;
int in2A2 = 10;
int pwm2B = 13;
int in2B1 = 11;
int in2B2 = 12;

const int trigLPin = 31;
const int echoLPin = 33;
const int trigFPin = 35;
const int echoFPin = 37;
const int trigRPin = 39;
const int echoRPin = 41;

String cmd = "";
String cmds = "";
int countcmds = 0;
int wayPointStatus = 1;
bool finishWP = false;
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
int countUpdateSensor = 0;
int goStatus = 0;
bool waypointStatus = false;

unsigned long distanceWP;
int GPSCourse;

double gpsLat;
double gpsLong;
int compHead;
int rangeLeft;
int rangeFront;
int rangeRight;

int turn_speed = 175;
int motor_speed = 250;

TinyGPSPlus gps;
HMC5883L compass;

void init_pin() {
  pinMode(trigLPin, OUTPUT);
  pinMode(echoLPin, INPUT);
  pinMode(trigFPin, OUTPUT);
  pinMode(echoFPin, INPUT);
  pinMode(trigRPin, OUTPUT);
  pinMode(echoRPin, INPUT);

  pinMode(pwm1A, OUTPUT);
  pinMode(pwm1B, OUTPUT);
  pinMode(in1A1, OUTPUT);
  pinMode(in1A2, OUTPUT);
  pinMode(in1B1, OUTPUT);
  pinMode(in1B2, OUTPUT);

  pinMode(pwm2A, OUTPUT);
  pinMode(pwm2B, OUTPUT);
  pinMode(in2A1, OUTPUT);
  pinMode(in2A2, OUTPUT);
  pinMode(in2B1, OUTPUT);
  pinMode(in2B2, OUTPUT);

  digitalWrite(in1A1, LOW);
  digitalWrite(in1A2, LOW);
  digitalWrite(in1B1, LOW);
  digitalWrite(in1B2, LOW);

  digitalWrite(in2A1, LOW);
  digitalWrite(in2A2, LOW);
  digitalWrite(in2B1, LOW);
  digitalWrite(in2B2, LOW);
}

void setup() {
  Serial.begin(115200); // to PC
  Serial1.begin(9600); // Telemetry
  Serial2.begin(9600); // GPS
  init_pin();
  delay(100);
  Serial.println("Robot Apung");
  delay(250);
  
  Wire.begin(); // Compass
  compass.begin();
  compass.setRange(HMC5883L_RANGE_1_3GA);
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
  compass.setDataRate(HMC5883L_DATARATE_30HZ);
  compass.setSamples(HMC5883L_SAMPLES_8);
  compass.setOffset(0, 0);

  startup(); // Wait GPS Locked // startup
  //setWaypoint(); // Set 5 Waypoints // setwaypoint
}

void loop() {

  if (waypointStatus == false) {
    if (Serial1.available() > 0) {
      int inByte = Serial1.read();
      Serial.println(inByte);
      switch (inByte) {
        case 'a':
          //addWP();
          while (1) {
            if (Serial1.available() > 0) {
              cmds = Serial1.readString();
            }
            delay(10);
            if (cmds != "") {
              addWP();
              break;
            }

          }
          break;
        case 'b':
          delWP();
          break;
        case 'c':
          checkWP();
          break;
        case 'd':
          clearWP();
          break;
        case 'e':
          goWP();
          break;
      }
    }
  } /*else if (waypointStatus == true) {
    if (Serial1.available() > 0) {
      cmds = Serial1.readString();
    }
  }*/

  if (countUpdateSensor > 200 && waypointStatus == false) {
    updateSensor();
    /*if (cmds != ""){
      Serial.println("data:" + String(cmds));
      cmds = "";
      }*/
    //FakeupdateSensor();
    countUpdateSensor = 0;
  }
  countUpdateSensor++;
  delay(10);
}
