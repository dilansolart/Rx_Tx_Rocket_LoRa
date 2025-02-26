#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");

  //Select the frequency accordng to your location
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
  // Change sync word (0xF1) to match the receiver LoRa
  // This code ensure that you don't get LoRa messages
  // from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF1);
  Serial.println("LoRa Initializing Successful!");
}

void loop() {
  Serial.print("Sending packet: ");
  // send packet
  LoRa.beginPacket();
  LoRa.print("Hello World");
  LoRa.endPacket();
  Serial.println("sent lora to on");

  delay(1000);
}