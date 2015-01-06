// Funcao Seek().ino
//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------
#include <SD.h>

File arquivo;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  if(!SD.begin(4)){
    Serial.println("Erro ao iniciar cartao SD");
    Serial.println("Diagnostico: Sem cartao SD");
    return;
  }
  else{
    Serial.println("Cartao SD Iniciado");
  }
  arquivo=SD.open("cadas.txt",FILE_WRITE);
    if(arquivo){
      arquivo.seek(0);
      arquivo.println("Autocore");
      arquivo.close();
    }
}

void loop() {

}
