#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

Servo servo_buka;
Servo servo_inductive;
Servo servo_capacitive;

LiquidCrystal_I2C Display(0x27 , 16 , 2);

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

  Display.init();
  Display.backlight();

  Serial.begin(9600);

  servo_buka.write(0);

}

void loop() {
  servo_inductive.write(90);
  servo_capacitive.write(90);
  Display.setCursor(0, 0);
  Display.print("S P E N C E R>/<");
  Display.setCursor(0, 1);
  Display.print("Kelompok 5");
  Deteksi();
  if (cek == 1) {
    Display.clear();
    Display.setCursor(1, 0);
    Display.print("Selamat Datang");
    Display.setCursor(1, 1);
    Display.print("Siapkan Sampah");
    for (int i = 0 ; i <= total_checks ; i++) {
      if (digitalRead(inductive) == 0) {
        Serial.println(String(1));
        servo_inductive.write(180);
        Display.clear();
        Display.setCursor(0, 0);
        Display.print("Sampah Anda>>>>>");
        Display.setCursor(0, 1);
        Display.print("Logam");
        delay(3000);
        return; 
      }
      else if (i == total_checks) {
        servo_inductive.write(0);
        delay(1000);
      }
      delay(interval);
    }

    for (int j = 0 ; j <= total_checks2 ; j++) {
      if (digitalRead(capacitive) == 1) {
        Serial.println(String(2));
        servo_capacitive.write(180);
        Display.clear();
        Display.setCursor(0, 0);
        Display.print("Sampah Anda>>>>>");
        Display.setCursor(0, 1);
        Display.print("Anorganik");
        delay(3000);
        return;
      }
      else if (j ==  total_checks2) {
        Serial.println(String(3));
        servo_capacitive.write(0);
        Display.clear();
        Display.setCursor(0, 0);
        Display.print("Sampah Anda>>>>>");
        Display.setCursor(0, 1);
        Display.print("Organik");
        delay(3000);
      }
      delay(interval);
    }
  }
  else {
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
