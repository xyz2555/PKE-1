#include <ESP32Servo.h>

Servo servo_logam;
Servo servo_organik;
Servo servo_anor;
Servo servo_buka;

const int trig_pin = 17;
const int echo_pin = 16;

const int sensor_induktif = ;
const int sensor_kapasitif = ;
const int sensor_infrared1 = ;
const int sensor_infrared2 = ;

float timing = 0.00;
float distance = 0.00;

int cek;

void setup(){
pinMode(21, OUTPUT);
pinMode(22, OUTPUT);
pinMode(23, OUTPUT);

pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);

pinMode(sensor_induktif, INPUT);
pinMode(sensor_kapasitif, INPUT);
pinMode(sensor_infrared1. INPUT);
pinMode(sensor_infrared2, INPUT);

digitalWrite(trig_pin, LOW);

servo_anor.attach(21);
servo_organik.attach(22);
servo_logam.attach(23);
servo_buka.attach(12);

Serial.begin(9600);

}

void loop(){
  Deteksi();
  if(cek == 1){

  }
  delay(500);
}

void Deteksi(){
digitalWrite(trig_pin, LOW);
delay(20);
digitalWrite(trig_pin, HIGH);
delay(40);
digitalWrite(trig_pin, LOW);

timing = pulseIn(echo_pin, HIGH);
distance = (timing * 0.034) / 2;  
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");

if (distance <= 10) {
servo_buka.write(180);
cek = 1;
} else {
servo_buka.write(0);
cek = 0;
}
  
delay(100);
}

void Sortir(){

}
