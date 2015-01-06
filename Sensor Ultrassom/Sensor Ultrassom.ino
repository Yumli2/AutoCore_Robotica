// Sensor Ultrassom.ino
//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------
#include "DHT.h"
#define DHTPIN A1 // pino de dados 
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

float Co=331.45;
float C;
float RaizT;
float T;

int echoPin= 13; //Pino 13 recebe o pulso do echo
int trigPin= 12; //Pino 12 envia o pulso para gerar o echo

long duracao, distancia; 

void setup()
{
Serial.begin(9600); //inicia a porta serial
dht.begin();//Inicializa a biblioteca
pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
}
 
void loop(){
	float t = dht.readTemperature();
	if (isnan(t)){
   		Serial.println("Falha na leitura do sensor DHT-11");
  	} 
	else{
    	Serial.print("Temperatura Ambiente: ");
    	Serial.print(t);
    	Serial.println(" *C");
  	}  	

	//seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
	digitalWrite(trigPin, LOW);
	// delay de 2 microssegundos
	delayMicroseconds(2);
	//seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
	digitalWrite(trigPin, HIGH);
	//delay de 10 microssegundos
	delayMicroseconds(10);
	//seta o pino 12 com pulso baixo novamente
	digitalWrite(trigPin, LOW);
	duracao=pulseIn(echoPin, HIGH);
	
	//=====================================================================================
	//Como calcular a distancia de acordo com a temperatura ambiente
	//1° temos que descobrir a temperatura ambiente
	//2° descobrir qual é a velocidade do som em 0°C
	//3° Saber a formula 
	//C=CoRaiz de T/To
	//T é a temperatura em KELVIN 0°C=273,15K
	//Co é uma constante no valor de 331,45m/s 

	T=t+273.15;
	T=T/273,15;
	RaizT=sqrt(T);
	C=331.45*RaizT;
	Serial.print("Velocidade do som m/s ");
	Serial.print(C);
	Serial.print("m/s");
	C=C*100; //Transforma m/s em cm/s
	Serial.print('\t');
	Serial.print('\t');
	Serial.print('\t');
	Serial.print("Velocidade do som cm/s ");
	Serial.print("cm/s");
	Serial.print(C);
	Serial.print('\t');
	Serial.print('\t');
	Serial.print('\t');
	distancia = ((duracao * C)/1000000)/2;
	Serial.print("Distancia em CM: ");
	Serial.println(distancia);
	Serial.println();
	Serial.println();
	Serial.println();
	
	
		
	delay(1000); //espera 1 segundo para fazer a leitura novamente
}
