#include <Servo.h>

Servo servo_buka;
Servo servo_inductive;
Servo servo_capacitive;

const int trig_pin = 12;
const int echo_pin = 13;

const int proxy = 2;
const int capacitive = 4;
const int inductive = 3;

float timing = 0.00;
float distance = 0.00;

//unsigned long startTime;
//boolean timerStarted = false;
//const unsigned long DETECTION_PERIOD = 5000;
//boolean objectDetected = false;

const unsigned long interval = 50;
const unsigned long total_checks = 100;
const unsigned long total_checks2 = 40;

int cek;

void setup() {
  pinMode(proxy, INPUT);
  pinMode(inductive, INPUT);
  pinMode(capacitive, INPUT);

  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  digitalWrite(trig_pin, LOW);
  servo_buka.attach(5);
  servo_inductive.attach(6);
  servo_capacitive.attach(9);

  Serial.begin(9600);

  servo_buka.write(0);

}

void loop() {
  servo_inductive.write(90);
  servo_capacitive.write(90);
  Deteksi();
  if (cek == 1) {
    for (int i = 0 ; i <= total_checks ; i++) {
      if (digitalRead(inductive) == 0) {
        Serial.println(String(1));
        servo_inductive.write(0);
        delay(1000);
        break;
      }
      else if (i == total_checks) {
        servo_inductive.write(180);
        delay(1000);
        //      Sortir2();
      }
      delay(interval);
    }

    for (int j = 0 ; j <= total_checks2 ; j++) {
      if (digitalRead(capacitive) == 1) {
        Serial.println(String(2));
        servo_capacitive.write(180);
        delay(1000);
        break;
      }
      else if (j ==  total_checks2) {
        servo_capacitive.write(0);
        delay(1000);
      }
      delay(interval);
    }
  }
  else{
    cek = 0;
    return;
  }
}
void Deteksi() {
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

  if (distance <= 20) {
    servo_buka.write(90);
    cek = 1;
  } else {
    servo_buka.write(0);
    cek = 0;
  }

  delay(1000);
}
