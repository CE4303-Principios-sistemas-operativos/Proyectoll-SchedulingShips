#include <Arduino.h>

String incomingByte;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    // read the incoming byte:
    incomingByte = Serial.readString();
    Serial.println(incomingByte);

    if(incomingByte=="a"){
       digitalWrite(13, HIGH);
    }

    if(incomingByte=="b"){
       digitalWrite(13, LOW);
    }
  }
}