#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "dygf76erdsdf"
#define BLYNK_TEMPLATE_NAME "fdskfj34bwne"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

  char auth[] = "apajajahalah";

  char ssid[] = "Hmmm";
  char password[] = "kafjasdkjf";


void setup(){

  Serial.begin(9600);
  Blynk.begin(auth, ssid, password, "blynk.cloud", 80);

}

void loop(){
  s
  Blynk.run();
}
