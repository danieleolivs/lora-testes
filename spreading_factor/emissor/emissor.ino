#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);

  Serial.println("Emissor");

  if(!LoRa.begin(915E6)){
    Serial.println("Erro de inicialização");
    while(true);
  }

  // variação de 6-12
  LoRa.setSpreadingFactor(10);

}

void loop() {
  LoRa.beginPacket();
  LoRa.print("Mensagem de teste!");
  LoRa.endPacket();

  delay(2000);  

}
