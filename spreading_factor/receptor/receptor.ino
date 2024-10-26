#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Receptor");

  if(!LoRa.begin(915E6)){
    Serial.println("Erro de inicialização");
    while(true);
  }

}

void loop() {
  int packet = LoRa.parsePacket();
  if(packet){
    Serial.print("Mensagem: ");

    while(LoRa.available()){
      String message = LoRa.readString();
      Serial.println(message);
    }
  }

}
