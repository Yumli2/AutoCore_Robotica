//Projeto Controle de Fluxo para Ponte em Ibutirama Bahia
//Empresa: Autocore Robótica
//Desenvolvedor: Yuri Lima
//Data de inicio: 25/04/2015
//=========================================================================================================================
//=========================================================================================================================
//Definições dos pinos Display de 7 segmentos
#define a 2 
#define b 3
#define cc 4 //usando apenas 'c' deu erro, não entendi o motivo!
#define d 5
#define e 6
#define f 7
#define g 8
//=========================================================================================================================
//Definição dos dígitos
#define d1 9
#define d2 10
#define d3 11
#define d4 12
//=========================================================================================================================
//Definição dos sensores
#define sensor1 50
#define sensor2 52
#define sensor3 53
#define sensor4 54
//=========================================================================================================================
//Variaveis dos calculos da função
#define del 2000//Regula o tempo
short int x = 200; //Define a velocidade da contagem
//Variaveis do Sentido AB
short int nAB=0,mAB=0,tempoAB=0,iAB=0,jAB=0,hAB=1,tempoInternoAB=0;
short int ch1,ch2;
boolean flagAB= true;
//=========================================================================================================================
//Variaveis do Sentidno BA
short int nBA=0,mBA=0,tempoBA=0,iBA=0,jBA=0,hBA=1,tempoInternoBA=0;
short int ch3,ch4;
boolean flagBA= true;
//=========================================================================================================================
//=========================================================================================================================
// inicialização do Arduino
void setup(){
	Serial.begin(9600);
	for(short int v=2;v<=12;v++){
    pinMode(v, OUTPUT);//Coloca os pinos 2 a 12 em OUTPUT
}
pinMode(sensor1, INPUT_PULLUP);
pinMode(sensor2, INPUT_PULLUP);
}
//=========================================================================================================================
//=========================================================================================================================
// loop principal do programa
void loop(){
	Sentido_AB();
	Sentido_BA();
}
//=========================================================================================================================
//=========================================================================================================================
void Sentido_AB(){
   if (digitalRead(sensor1)==HIGH && jAB==0){ //O carro passou pelo sensor sentido AB
   	iAB=0;
   	chave1();
   }   
  if (digitalRead(sensor1)==HIGH && jAB==1){ //Quando o segundo ou demais carros passa pelo sensor do sentido AB
  	tempoInternoAB=0;  

  	while((tempoAB>0) || (flagAB==true)){ 
  		while(digitalRead(sensor2)==LOW ){
  			clearLEDs();
  			pickDigit(1);
  			pickNumber(tempoAB/x%10);
  			delayMicroseconds(del);
  			
  			clearLEDs();
  			pickDigit(2);
  			pickNumber((tempoAB/x/10)%10);
  			delayMicroseconds(del);
  			if(tempoAB>0){
          tempoAB--; // incrementa n
      }
        tempoInternoAB+=1; // Tem que ser tempoInterno +1 por que Tempo-- vai decrementar o tempo 1000 por exemplo de um a um
        if(digitalRead(sensor2)!=LOW){
        	tempoAB=0;
        	goto paraFlagAB;
        }
    }
    paraFlagAB:
    flagAB=false;
} 
Serial.print("tempo: ");
Serial.println(tempoAB);
Serial.print("tempo Interno: ");
Serial.println(tempoInternoAB);
tempoAB= tempoInternoAB;
ch1=LOW; 
}
}
//=========================================================================================================================
//=========================================================================================================================
void Sentido_BA(){
   if (digitalRead(sensor3)==HIGH && jBA==0){ //O carro passou pelo sensor no sentido BA
   	iBA=0;
   	chave2();
   }   
  if (digitalRead(sensor3)==HIGH && jBA==1){ //Quando o segundo ou demais carros passa pelo sensor do sentido BA
  	tempoInternoBA=0;  
  	while((tempoBA>0) || (flagBA==true)){ 
  		while(digitalRead(sensor4)==LOW ){
  			clearLEDs();
  			pickDigit(3);
  			pickNumber(tempoBA/x%10);
  			delayMicroseconds(del);
  			
  			clearLEDs();
  			pickDigit(4);
  			pickNumber((tempoBA/x/10)%10);
  			delayMicroseconds(del);
  			if(tempoBA>0){
          		tempoBA--; // incrementa n
          	}
        	tempoInternoBA+=1; // Tem que ser tempoInterno +1 por que Tempo-- vai decrementar o tempo 1000 por exemplo de um a um
        	if(digitalRead(sensor4)!=LOW){
        		tempoBA=0;
        		goto paraFlagBA;
        	}
        }
        paraFlagBA:
        flagBA=false;
    } 
    Serial.print("tempo: ");
    Serial.println(tempoBa);
    Serial.print("tempo Interno: ");
    Serial.println(tempoInternoBA);
    tempoBA= tempoInternoBA;
    ch3=LOW;
    
}
}
//=========================================================================================================================
//=========================================================================================================================
//Teste logico dos Sensores  
void chave1(){
	while (digitalRead(sensor2)==LOW){
		Serial.print(nAB);
		Serial.print(" - ");
		Serial.print(iAB);
		Serial.println(" Segundos");
		iAB++;
        nAB = nAB+200; // Incrementa n
        delay(1000); //Segundos
    }
    ch1=LOW;
    jAB=1;
    tempoAB += nAB;
}
void chave2(){
	while (digitalRead(sensor4)==LOW){
		Serial.print(nBA);
		Serial.print(" - ");
		Serial.print(iBA);
		Serial.println(" Segundos");
		iBA++;
        nBA = nBA+200; // Incrementa n
        delay(1000); //Segundos
    }
    ch3=LOW;
    jBA=1;
    tempoBA += nBa;
}
//=========================================================================================================================
//=========================================================================================================================
//Subrotina para multiplexar os dígitos do display
void pickDigit(int x){
  digitalWrite(d1, HIGH);// valor HIGH no pino desabilita o dígito(display)
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  switch(x){ // cria uma estrutura switch, tendo como entrada o número do digito(display) a ser habilitado
    case 1: digitalWrite(d1, LOW); // colocando LOW no pino, estamos habilitando o acendimento dos segmentos                             
    	break; // executou? sai da estutura
    	case 2: digitalWrite(d2, LOW); 
    	break;
    	case 3: digitalWrite(d3, LOW); 
    	break;
    	default: digitalWrite(d4, LOW); 
    	break;
    }
}
//=========================================================================================================================
//=========================================================================================================================
//Subrotina para acender um determinado número no display
int pickNumber(int x){
  switch(x){ // cria uma estrutura switch para seleção do numero
  	default: 
      zero(); // chama rotina para apresentar número 0 no display 
      return 0;
      break;  // executou? retorna da subrotina
      case 1: 
      one();
      return 1; 
      break;
      case 2: 
      two();
      return 2; 
      break;
      case 3: 
      three(); 
      return 3;
      break;
      case 4: 
      four();
      return 4; 
      break;
      case 5: 
      five();
      return 5; 
      break;
      case 6: 
      six(); 
      return 6;
      break;
      case 7: 
      seven();
      return 7; 
      break;
      case 8: 
      eight();
      return 8; 
      break;
      case 9: 
      nine(); 
      return 9;
      break;
  }
}
//=========================================================================================================================
//=========================================================================================================================
//Subrotina para apagar todos os segmentos
void clearLEDs(){
  digitalWrite(a, LOW); // valor low no pino, apaga segmento
  digitalWrite(b, LOW);
  digitalWrite(cc,LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);  
}
//=========================================================================================================================
//=========================================================================================================================
// mostra número sero no display
void zero(){
  digitalWrite(a, HIGH); // valor HIGH no pino, acende segmento
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one(){
	digitalWrite(a, LOW);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, LOW);
}

void two(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(cc, LOW);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, LOW);
	digitalWrite(g, HIGH);
}

void three(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, HIGH);
}

void four(){
	digitalWrite(a, LOW);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}

void five(){
	digitalWrite(a, HIGH);
	digitalWrite(b, LOW);
	digitalWrite(cc, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}

void six(){
	digitalWrite(a, LOW);
	digitalWrite(b, LOW);
	digitalWrite(cc, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}

void seven(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, LOW);
	digitalWrite(g, LOW);
}

void eight(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, HIGH);
	digitalWrite(e, HIGH);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}

void nine(){
	digitalWrite(a, HIGH);
	digitalWrite(b, HIGH);
	digitalWrite(cc, HIGH);
	digitalWrite(d, LOW);
	digitalWrite(e, LOW);
	digitalWrite(f, HIGH);
	digitalWrite(g, HIGH);
}
// Fim da Compilação

