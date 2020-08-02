void forward(){
  Serial.println("Forward");
  analogWrite(enA, motor_speed);
  analogWrite(enB, motor_speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void reverse(){
  Serial.println("Reverse");
  analogWrite(enA, motor_speed);
  analogWrite(enB, motor_speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turn_left(){
  Serial.println("Turn Left");
  analogWrite(enA, turn_speed);
  analogWrite(enB, turn_speed);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turn_right(){
  Serial.println("Turn Right");
  analogWrite(enA, turn_speed);
  analogWrite(enB, turn_speed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void brake(){
  Serial.println("Brake");
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
