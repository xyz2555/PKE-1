int proxy = 2;
int capacitive = 5;
int inductive = 8;

//int servo_p = 3;
//int servo_i = 6; 
//int servo_c = 9;

void setup() {
  Serial.begin(9600);

  pinMode(proxy, INPUT);
  pinMode(inductive, INPUT);
  pinMode(capacitive, INPUT);

//  pinMode(servo_p, OUTPUT);
//  pinMode(servo_i, OUTPUT);
//  pinMode(servo_c, OUTPUT);
}

void loop() {
  if(digitalRead(proxy) == 0){
    Serial.println(String(1));
  }

//  else if(digitalRead(capacitive) == 0){
//    Serial.println(String(2));
//  }

  else if(digitalRead(inductive) == 0){
    Serial.println(String(3));
  }

  delay(1000);
//  if(sensor == 0){
//    Serial.println(String(1));  
//  }
//   delay(1000);
//  Serial.println(String(2));
//  delay(1000);
//  Serial.println(String(3));
//  delay(1000);
  // put your main code here, to run repeatedly:

}
