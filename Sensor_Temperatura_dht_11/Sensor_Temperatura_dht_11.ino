//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------

 
// Conecte pino 1 do sensor (esquerda) ao +5V
// Conecte pino 2 do sensor ao pino de dados definido em seu Arduino
// Conecte pino 4 do sensor ao GND
// Conecte o resistor de 10K entre pin 2 (dados) 
// ao pino 1 (VCC) do sensor
#include "DHT.h"
 
#define DHTPIN A1 // pino de dados 
#define DHTTYPE DHT11 // DHT 11
#define LED 7 //Pino para acender um led

DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("Analisando temperatura e humidity!");
  dht.begin();//Inicializa a biblioteca
  pinMode(LED, OUTPUT);//Seta o LED do pino 7 como saida

}
 
 void alerta(){
	digitalWrite(LED,!digitalRead(LED));//Acende e apaga o LED do pino 7
  	delay(500);//500 milis segundo
  	Serial.println("Alerta temperatura elevada!");//O texto que você quiser

 }
void loop() 
{
   // A leitura da temperatura e umidade pode levar 250ms!
  //  O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity(); //Chama a função dentro da biblioteca para realizar a leitura da Umidade e guarda na variavel h
  float t = dht.readTemperature(); //Chama a função dentro da biblioteca para realizar a leitura da Umidade e guarda na variavel t
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) //Verifica se a
  {
    Serial.println("Falha na leitura do sensor DHT-11");
  } 
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
    delay(2000);
    //Testa quando a temperatura for maior que 34*C ele vai chamar a função Alerta para ligar e desligar o LED
    if(t>=34){
    	alerta();
    }
  }
}
