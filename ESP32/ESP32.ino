#define BLYNK_TEMPLATE_NAME "SPENCER Trash Sorting"
#define BLYNK_AUTH_TOKEN "XWQE2SZN_mMvHxOaxZOVL6yRqRJ18k5D"
#define BLYNK_TEMPLATE_ID "TMPL65ZJT65U9"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Redmi 9T";
char password[] = "Jangantanya";

BlynkTimer timer;

#define RXp2 16
#define TXp2 17

int logam = 0;
int anorganik = 0;
int organik = 0;

HardwareSerial mySerial(2);

void setup() {
  delay(5000);
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXp2, TXp2);

  Blynk.begin(auth, ssid, password);
  timer.setInterval(1000L, Kerja);

  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  Blynk.run();
  timer.run();

  if (mySerial.available()) {
    String pesan = mySerial.readStringUntil('\n');
    Serial.println("Isi: " + pesan);

    pesan.trim();

    if (pesan == "1") {
      logam++;
    }
    else if (pesan == "2") {
      anorganik++;
    }
    else if (pesan == "3") {
      organik++;
    }
  }
  delay(700);

}

void Kerja() {
  Blynk.virtualWrite(V0, logam);
  Blynk.virtualWrite(V1, anorganik);
  Blynk.virtualWrite(V2, organik);
}
