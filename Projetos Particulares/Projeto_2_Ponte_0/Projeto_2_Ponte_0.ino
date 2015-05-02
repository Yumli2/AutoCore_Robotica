//Projeto_2_Ponte_0.ino

// definição dos pinos dos segmentos
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;


//definição dos pinos dos dígitos
int di1 = 9;
int di2 = 10;
int di3 = 11;
int di4 = 12;

// outras definições
long n ;
long m ;
int y= 100;
int del2 = 2200;
int x = 100;
int del = 2200;
int z = 1;
int w = 1;
int loopcount = 0;
int tempo = 0;
int tempo2 = 0;
int testch;

int ch2,ch1;
// inicialização do Arduino
void setup()
{
  Serial.begin(9600);
  pinMode(di1, OUTPUT);
  pinMode(di2, OUTPUT);
  pinMode(di3, OUTPUT);
  pinMode(di4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  
 while (testch==0){
  Serial.println("sd");
   ch1 = digitalRead(A4); // teste logico das chaves
   ch2 = digitalRead(A5);
   if (ch1==HIGH){
      z=1;
     chave1();
    }
    else if(ch2==HIGH){
      w=1;
      chave2();
    }
    else{
      w=0;
      z=0;
    }
    testch = w+z;
  }
  Serial.println("sd");
}
  void chave1(){
while (tempo==0)
{
  ch1 = digitalRead(A4);
  if (ch1==HIGH)
   {
    n= n+100; // Incrementa n
  delay(1000);
 }
   else
   {tempo = n;
     chave2();}
   
}
  }
void chave2(){
  
while (tempo2==0)
{
  int ch2 = digitalRead(A5);
  if (ch2 == HIGH)
    {
  delay(1000);  
    m=m+100; // Incrementa n
    }  
  else
  {tempo2 = m;
    chave1();}
}
}


// loop principal do programa
void loop(){
  //Serial.println(ch1);
   //Serial.println(ch2);
	if (n<=0){//100<=0? n--
    	digitalWrite(A1,HIGH);
    }
    else{
    	delay(3);
     	n--; // decrementa n
    }
    if (m<=0){
     digitalWrite(A0,HIGH);
    }
    else{
    	delay(3);
     	m--; // decrementa n
    }
     
    if (digitalRead(A4) == LOW){ // verifica se botão foi pressionado
  		n = tempo; // se sim zera o contador
    	digitalWrite(A1,LOW);
 	}
   if (digitalRead(A5) == LOW){ // verifica se botão foi pressionado
  		m = tempo2; // se sim zera o contador
    	digitalWrite(A0,LOW);
  	}
  
  
  	if ( digitalRead(A5) == HIGH){ // verifica se botão foi pressionado
  		clearLEDs(); // apaga todos os segmentos
    	pickDigit(1); // seleciona dígito 1
    	pickNumber((m/y/10)%10); // gera o número a ser mostrado
                             // baseado em n e x
    	delayMicroseconds(del2); // delay em microsegundos
  
  		clearLEDs();
  		pickDigit(2);
  		pickNumber((m/y%10));
  		delayMicroseconds(del2);
  	}
  	else{
   		if ( digitalRead(A4) == HIGH){ // verifica se botão foi pressionado
  			clearLEDs();
  			pickDigit(3);
  			//dispDec(3);
  			pickNumber((n/x/10)%10);
  			delayMicroseconds(del);
  
  			clearLEDs();
  			pickDigit(4);
  			pickNumber(n/x%10);
  			delayMicroseconds(del);
  		}
  		else{
  			digitalWrite(di1, HIGH);// valor HIGH no pino desabilita o dígito
 			digitalWrite(di2, HIGH);
  			digitalWrite(di3, HIGH);
  			digitalWrite(di4, HIGH);  
		}
	}
}

// subrotina para multiplexar os dígitos do display
void pickDigit(int x){
	digitalWrite(di1, HIGH);// valor HIGH no pino desabilita o dígito
  	digitalWrite(di2, HIGH);
  	digitalWrite(di3, HIGH);
  	digitalWrite(di4, HIGH);
  
	switch(x){ // cria uma estrutura switch, tendo como entrada
        // o número do display a ser habilitado
  	  	case 1: 
    	digitalWrite(di1, LOW); // colocando LOW no pino, estamos habilitando o acendimento dos segmentos
        break;   // executou? sai da estutura                  
        case 2: 
      	digitalWrite(di2, LOW); 
      	break;
    	case 3: 
      	digitalWrite(di3, LOW); 
     	break;
    	default: 
      	digitalWrite(di4, LOW); 
      	break;
  	}
}

// subrotina para acender um determinado número no display
void pickNumber(int x)
{
  switch(x) // cria uma estrutura switch para seleção
  {
    default: 
      zero(); // chama rotina para apresentar número 0 no display 
      break;  // executou? retorna da subrotina
    case 1: 
      one(); 
      break;
    case 2: 
      two(); 
      break;
    case 3: 
      three(); 
      break;
    case 4: 
      four(); 
      break;
    case 5: 
      five(); 
      break;
    case 6: 
      six(); 
      break;
    case 7: 
      seven(); 
      break;
    case 8: 
      eight(); 
      break;
    case 9: 
      nine(); 
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