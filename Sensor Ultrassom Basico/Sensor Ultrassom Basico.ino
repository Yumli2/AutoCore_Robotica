//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------
int echoPin= 13; //Pino 13 recebe o pulso do echo
int trigPin= 12; //Pino 12 envia o pulso para gerar o echo

long duracao, distancia; 

void setup(){
Serial.begin(9600); //inicia a porta serial
pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
}
 
void loop(){
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
	distancia = duracao / 29.4 / 2;
	Serial.print("A distancia em CM ");
	Serial.println(distancia);
	if(distancia<=5){
		digitalWrite(3,1);
	}
	else digitalWrite(3,0);

	delay(1000);
}
