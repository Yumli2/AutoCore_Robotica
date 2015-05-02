// definição dos pinos dos segmentos
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
//int p = 8;

//definição dos pinos dos dígitos
int d1 = 9;
int d2 = 10;
int d3 = 11;
int d4 = 12;
boolean flag= true; 
// outras definições
int tempo1; //20000==99
int x = 200; 
int del = 2000; //regula o tempo

// inicialização do Arduino
void setup()
{
	Serial.begin(9600);
  	pinMode(d1, OUTPUT);
  	pinMode(d2, OUTPUT);
  	pinMode(d3, OUTPUT);
  	pinMode(d4, OUTPUT);
  	pinMode(a, OUTPUT);
  	pinMode(b, OUTPUT);
  	pinMode(c, OUTPUT);
  	pinMode(d, OUTPUT);
  	pinMode(e, OUTPUT);
  	pinMode(f, OUTPUT);
  	pinMode(g, OUTPUT);
  	//pinMode(p, OUTPUT);
}

// loop principal do programa
void loop()
{
	
		long n=tempo1();
    	clearLEDs();
  	  	pickDigit(1);
 	  	pickNumber(n/x%10);
  		delayMicroseconds(del);

 		clearLEDs();
  		pickDigit(2);
  		pickNumber((n/x/10)%10);
  		delayMicroseconds(del);
  		n--; // incrementa n
  		if (digitalRead(A4) == HIGH){ // verifica se botão foi pressionado
    		Serial.println(digitalRead(A4));
   			 n = 20000; // se sim zera o contador
  		}
  		
}

int tempo1(){
	for(int i=0; i<=20000;i=i+200){
			tempo1=i;
			delay(300);
			if(digitalRead(A5)==LOW){
				flag=false;
			}
		
	}
	return tempo1;
}
int chaveSensor2(){

}

// subrotina para multiplexar os dígitos do display
void pickDigit(int x)
{
  digitalWrite(d1, HIGH);// valor HIGH no pino desabilita o dígito
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  
  switch(x) // cria uma estrutura switch, tendo como entrada
            // o número do display a ser habilitado
  {
    case 1: 
      digitalWrite(d1, LOW); // colocando LOW no pino, estamos habilitando
                             // o acendimento dos segmentos
      break; // executou? sai da estutura
    case 2: 
      digitalWrite(d2, LOW); 
      break;
    case 3: 
      digitalWrite(d3, LOW); 
      break;
    default: 
      digitalWrite(d4, LOW); 
      break;
  }
}

// subrotina para acender um determinado número no display
int pickNumber(int x)
{
  switch(x) // cria uma estrutura switch para seleção
  {
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

//void dispDec(int x)
//{
  //digitalWrite(p, HIGH);
//}

// subrotina para apagar todos os segmentos
void clearLEDs()
{
  digitalWrite(a, LOW); // valor low no pino, apaga segmento
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  //digitalWrite(p, LOW);
}

// mostra número sero no display
void zero()
{
  digitalWrite(a, HIGH); // valor HIGH no pino, acende segmento
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void two()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void three()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void four()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void five()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
// Fim da Compilação