int sensor = 2;

void setup() {
  Serial.begin(9600);

  pinMode(sensor, INPUT);
  // put your setup code here, to run once:

}

void loop() {
  if(sensor == 0){
    Serial.println(String(1));  
  }
   delay(1000);
//  Serial.println(String(2));
//  delay(1000);
//  Serial.println(String(3));
//  delay(1000);
  // put your main code here, to run repeatedly:

}
