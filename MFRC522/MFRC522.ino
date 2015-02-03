
#include <SPI.h>
#include <MFRC522.h>

 
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Cria uma instancia MFRC522 da biblioteca.

/*
* Typical pin layout used:
 * ------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino
 *             Reader/PCD   Uno           Mega      Nano v3
 * Signal      Pin          Pin           Pin       Pin
 * ------------------------------------------------------------
 * RST/Reset   RST          9             5         D9
 * SPI SS      SDA(SS)      10            53        D10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11
 * SPI MISO    MISO         12 / ICSP-1   50        D12
 * SPI SCK     SCK          13 / ICSP-3   52        D13
 */
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");
  Serial.println();
}
 
void loop() 
{


  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()){
      
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()){
     
    return;
  }
   Serial.print("Tamanho da tag formada em modulos: ");
   Serial.println(mfrc522.uid.size);
   Serial.println();
   Serial.print("Endereco da tag de cada modulo: ");
   Serial.print(mfrc522.uid.uidByte[0]);
   Serial.print('\t');
   Serial.print(mfrc522.uid.uidByte[1]);
   Serial.print('\t');
   Serial.print(mfrc522.uid.uidByte[2]);
   Serial.print('\t');
   Serial.print(mfrc522.uid.uidByte[3]);
   Serial.println('\t');
  //Mostra UID na serial
  Serial.print('\t');
  Serial.print('\t');
  Serial.print('\t');
  Serial.print('\t');
  Serial.print('\t');
  Serial.print("UID da tag :");

  String UID= "";
  for (byte i = 0; i < mfrc522.uid.size; i++){//vê o tamanho o UID que é em modulos
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");//Decimal
     Serial.print(mfrc522.uid.uidByte[i], HEX);//Hexadecimalm
     delay(1000);
     UID.concat(String(mfrc522.uid.uidByte[i]< 0x10 ? " 0" : " "));
     UID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  UID.toUpperCase();
  Serial.println(UID.substring(1));
  
  Serial.println();
  Serial.print("Mensagem : ");
  UID.toUpperCase();
  if (UID.substring(1) == "8C 0A FF 04") 
  {
    Serial.println("Acesso liberado!");
    //digitalWrite(pin, value);
    delay(3000);
    return;    
  }
 
  else if (UID.substring(1) == "54 34 15 15") 
  {
    Serial.println("Ola Yuri !!!");
    Serial.println();
    Serial.println("Seja Bem Vindo !");
    delay(3000);
    return;   
  }
  else if(UID.substring(1) != "54 34 15 15" && "8C 0A FF 04"){
  Serial.println("Acesso Negado!");
  delay(3000);
    return;  
  }


  
} 