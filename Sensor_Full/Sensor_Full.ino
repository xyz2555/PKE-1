int proxy = 16;
int inductive = 17;
int capacitive = 5;

int servo_p = 18;
int servo_i = 19; 
int servo_c = 21;

void setup() {
  pinMode(proxy, INPUT);
  pinMode(inductive, INPUT);
  pinMode(capacitive, INPUT);

  pinMode(servo_p, OUTPUT);
  pinMode(servo_i, OUTPUT);
  pinMode(servo_c, OUTPUT);
}

void loop() {
  if(digitalRead(proxy) == 0){
    digitalWrite(servo_p, HIGH);
    delay(1000);
  }

  else if (digitalRead(inductive) == 0){
  digitalWrite(servo_i, HIGH);
  delay(1000);
  }

  else if (digitalRead(capacitive) == 0){
    digitalWrite(servo_c, HIGH);
    delay(1000);
  }

  digitalWrite(servo_p, LOW);
  digitalWrite(servo_i, LOW);
  digitalWrite(servo_c, LOW);
  delay(500);
}
