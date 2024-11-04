//Sensor proximity, Biru = -, Coklat = +, Hitam = Data

int sensor = 19;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(18, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(sensor));
  delay(500);
  if(digitalRead(sensor) == 1){
    Serial.println(digitalRead(sensor));
    digitalWrite(18, HIGH);
  }
  delay(500);
  digitalWrite(18,LOW);
  delay(500);
}
