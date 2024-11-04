#define RXp2 16
#define TXp2 17

HardwareSerial mySerial(2);

void setup() { 
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, RXp2, TXp2); 

  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
}

void loop() {
  if(mySerial.available()){
    String pesan = mySerial.readStringUntil('\n');
    Serial.println("Isi: " + pesan);  

    pesan.trim();

    if (pesan == "1"){
      digitalWrite(18, HIGH);
      digitalWrite(19,LOW);
      digitalWrite(21, LOW);
Serial.println("Satu");
    }
    else if (pesan == "2"){
      digitalWrite(19, HIGH);
      digitalWrite(18,LOW);
      digitalWrite(21, LOW);
Serial.println("Dua");
    }
    else if (pesan == "3"){
      digitalWrite(21, HIGH);
      digitalWrite(19,LOW);
      digitalWrite(18, LOW);      
Serial.println("Tiga");
    }
  }
  delay(700);
  digitalWrite(18,LOW);
  digitalWrite(19,LOW);
  digitalWrite(21,LOW);
  
}
