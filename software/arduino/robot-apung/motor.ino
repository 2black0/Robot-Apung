void pump_on()
{
  Serial.println("Pump ON");
  analogWrite(pwm2A, motor_speed);
  analogWrite(pwm2B, motor_speed);

  digitalWrite(in2A1, HIGH);
  digitalWrite(in2A2, LOW);
  digitalWrite(in2B1, HIGH);
  digitalWrite(in2B2, LOW);
}

void pump_off()
{
  Serial.println("Pump OFF");
  analogWrite(pwm2A, motor_speed);
  analogWrite(pwm2B, motor_speed);

  digitalWrite(in2A1, LOW);
  digitalWrite(in2A2, LOW);
  digitalWrite(in2B1, LOW);
  digitalWrite(in2B2, LOW);
}

void forward()
{
  Serial.println("Forward");
  analogWrite(pwm1A, motor_speed);
  analogWrite(pwm1B, motor_speed);

  digitalWrite(in1A1, HIGH);
  digitalWrite(in1A2, LOW);
  digitalWrite(in1B1, HIGH);
  digitalWrite(in1B2, LOW);
}

void reverse()
{
  Serial.println("Reverse");
  analogWrite(pwm1A, motor_speed);
  analogWrite(pwm1B, motor_speed);

  digitalWrite(in1A1, LOW);
  digitalWrite(in1A2, HIGH);
  digitalWrite(in1B1, LOW);
  digitalWrite(in1B2, HIGH);
}

void turn_left()
{
  Serial.println("Turn Left");
  analogWrite(pwm1A, turn_speed);
  analogWrite(pwm1B, turn_speed);

  digitalWrite(in1A1, LOW);
  digitalWrite(in1A2, HIGH);
  digitalWrite(in1B1, HIGH);
  digitalWrite(in1B2, LOW);
}

void turn_right()
{
  Serial.println("Turn Right");
  analogWrite(pwm1A, turn_speed);
  analogWrite(pwm1B, turn_speed);

  digitalWrite(in1A1, HIGH);
  digitalWrite(in1A2, LOW);
  digitalWrite(in1B1, LOW);
  digitalWrite(in1B2, HIGH);
}

void brake()
{
  Serial.println("Brake");
  analogWrite(pwm1A, 0);
  analogWrite(pwm1B, 0);

  digitalWrite(in1A1, LOW);
  digitalWrite(in1A2, LOW);
  digitalWrite(in1B1, LOW);
  digitalWrite(in1B2, LOW);
}