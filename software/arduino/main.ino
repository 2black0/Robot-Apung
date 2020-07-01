#include <TinyGPS++.h>
#include <timer.h>

TinyGPSPlus gps;
Timer timer;

// define Pin
int D1_enA = 2;
int D1_in1 = 3;
int D1_in2 = 4;
int D1_enB = 7;
int D1_in3 = 5;
int D1_in4 = 6;
int D2_enA = 8;
int D2_in1 = 9;
int D2_in2 = 10;
int D2_enB = 13;
int D2_in3 = 11;
int D2_in4 = 12;
int SR04_L_trigPin = 31;
int SR04_L_echoPin = 33;
int SR04_R_trigPin = 35;
int SR04_R_echoPin = 37;
int SR04_F_trigPin = 39;
int SR04_F_echoPin = 41;

long SR04_L_duration;
int SR04_L_distance;
long SR04_R_duration;
int SR04_R_distance;
long SR04_F_duration;
int SR04_F_distance;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600); // gps
  Serial2.begin(9600); // telemetry
  init_pin();
  timer.setInterval(5000);
  timer.setCallback(kirim_GPS);
  timer.start();
}

// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------

void loop()
{
  // untuk test pilih salah satu dan buka komentar
  //test_jalan();
  //test_sensor();
  timer.update();
}

// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------

void test_jalan()
{
  // gerak_maju sekitar 10 detik
  Serial2.print('gerak_maju');
  for (int i = 0; i <= 100; i++)
  {
    gerak_maju(200);
    delay(100);
  }

  // gerak_mundur sekitar 10 detik
  Serial2.print('gerak_mundur');
  for (int i = 0; i <= 100; i++)
  {
    gerak_mundur(200);
    delay(100);
  }

  // gerak_kiri sekitar 5 detik
  Serial2.print('gerak_kiri');
  for (int i = 0; i <= 50; i++)
  {
    gerak_kiri(150);
    delay(100);
  }

  // gerak_kanan sekitar 5 detik
  Serial2.print('gerak_kanan');
  for (int i = 0; i <= 50; i++)
  {
    gerak_kanan(150);
    delay(100);
  }
}

void test_sensor()
{
  sensor_kiri();
  sensor_kanan();
  sensor_depan();

  Serial.println("Sensor Kiri: " + String(SR04_L_distance) + "cm");
  Serial.println("Sensor Kanan: " + String(SR04_R_distance) + "cm");
  Serial.println("Sensor Depan: " + String(SR04_F_distance) + "cm");
}

void init_pin()
{
  pinMode(D1_enA, OUTPUT);
  pinMode(D1_in1, OUTPUT);
  pinMode(D1_in2, OUTPUT);
  pinMode(D1_enB, OUTPUT);
  pinMode(D1_in3, OUTPUT);
  pinMode(D1_in4, OUTPUT);

  pinMode(D2_enA, OUTPUT);
  pinMode(D2_in1, OUTPUT);
  pinMode(D2_in2, OUTPUT);
  pinMode(D2_enB, OUTPUT);
  pinMode(D2_in3, OUTPUT);
  pinMode(D2_in4, OUTPUT);

  pinMode(SR04_L_trigPin, OUTPUT);
  pinMode(SR04_L_echoPin, INPUT);
  pinMode(SR04_R_trigPin, OUTPUT);
  pinMode(SR04_R_echoPin, INPUT);
  pinMode(SR04_F_trigPin, OUTPUT);
  pinMode(SR04_F_echoPin, INPUT);

  digitalWrite(D1_in1, LOW);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, LOW);

  digitalWrite(D2_in1, LOW);
  digitalWrite(D2_in2, LOW);
  digitalWrite(D2_in3, LOW);
  digitalWrite(D2_in4, LOW);
}

void gerak_maju(int kecepatan)
{
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);

  analogWrite(D1_enA, kecepatan);
  analogWrite(D1_enB, kecepatan);
}

void gerak_mundur(int kecepatan)
{
  digitalWrite(D1_in1, LOW);
  digitalWrite(D1_in2, HIGH);
  digitalWrite(D1_in3, LOW);
  digitalWrite(D1_in4, HIGH);

  analogWrite(D1_enA, kecepatan);
  analogWrite(D1_enB, kecepatan);
}

void gerak_kiri(int kecepatan)
{
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);

  analogWrite(D1_enA, kecepatan);
  analogWrite(D1_enB, 0);
}

void gerak_kanan(int kecepatan)
{
  digitalWrite(D1_in1, HIGH);
  digitalWrite(D1_in2, LOW);
  digitalWrite(D1_in3, HIGH);
  digitalWrite(D1_in4, LOW);

  analogWrite(D1_enA, 0);
  analogWrite(D1_enB, kecepatan);
}

void sensor_kiri()
{
  digitalWrite(SR04_L_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SR04_L_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(SR04_L_trigPin, LOW);

  SR04_L_duration = pulseIn(SR04_L_echoPin, HIGH);
  SR04_L_distance = SR04_L_duration * 0.034 / 2;
}

void sensor_kanan()
{
  digitalWrite(SR04_R_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SR04_R_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(SR04_R_trigPin, LOW);

  SR04_R_duration = pulseIn(SR04_R_echoPin, HIGH);
  SR04_R_distance = SR04_R_duration * 0.034 / 2;
}

void sensor_depan()
{
  digitalWrite(SR04_F_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SR04_F_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(SR04_F_trigPin, LOW);

  SR04_F_duration = pulseIn(SR04_F_echoPin, HIGH);
  SR04_F_distance = SR04_F_duration * 0.034 / 2;
}

void kirim_GPS()
{
  String lati;
  String longi;
  String loc;

  if (gps.encode(Serial1.read()))
  {
    if (gps.location.isValid())
    {
      lati = gps.location.lat();
      longi = gps.location.lng();
      loc = "Lat: " + lati + "; Long: " + longi;
      Serial2.print(loc);
    }
    else
    {
      Serial2.print("Location: Not Available");
    }
  }
}