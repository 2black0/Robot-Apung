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

void setup() {
  Serial.begin(115200); // to PC
  Serial1.begin(9600); // Telemetry
  Serial2.begin(9600); // GPS
  delay(100);

  pinMode(trigLPin, OUTPUT);
  pinMode(echoLPin, INPUT);
  pinMode(trigFPin, OUTPUT);
  pinMode(echoFPin, INPUT);
  pinMode(trigRPin, OUTPUT);
  pinMode(echoRPin, INPUT);  

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

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
  /*while (Serial1.available()) {
    cmds = Serial1.readString();
    cmd = cmds.substring(0, 3);
    countcmds++;
    if(countcmds >= 100) break;
    }
    if (cmd != ""){
    Serial.println(cmd);
    }
    if (cmd == "ADD"){
    if(finishWP == false){
      finishWP = addWP();
    }
    }
    if (cmd == "DEL"){
    delWP();
    }
    if (cmd == "CHK"){
    checkWP();
    }
    if (cmd == "CLR"){
    clearWP();
    }
    if (cmd == "GOO"){
    goWP();
    }
    updateSensor();
    delay(1000);*/

  if (Serial1.available() > 0) {
    int inByte = Serial1.read();
    Serial.println(inByte);
    switch (inByte) {
      case 'a':
        addWP();
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
  if(countUpdateSensor > 100){
    updateSensor();
    countUpdateSensor = 0;
  }
  countUpdateSensor++;
  //delay(1000);
}
