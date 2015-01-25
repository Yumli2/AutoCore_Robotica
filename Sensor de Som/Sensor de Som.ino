// Sensor de Som.ino

int leituras = 100; //Define o numero de leituras 
int pinosinal = A0; //Pino ligado ao pino OUT do modulo sensor de som  
long sinal;   //Armazena o valor lido do Sensor de Som  
long soma = 0; //Armazena o valor total das n Leituras
long nivel =0; //Armazena o valor medio  
int mostranivel = 0; //Utilizado para dar 
 
   
void setup(){   
 Serial.begin(9600);  	
 pinMode(pinosinal, INPUT); //Define o pino de sinal como Entrada
 for(int i=2; i<=11; i++){pinMode(i, OUTPUT);}  
 /*
 pinMode (2, OUTPUT);
 pinMode (3, OUTPUT);
 pinMode (4, OUTPUT);
 pinMode (5, OUTPUT);
 pinMode (6, OUTPUT);
 pinMode (7, OUTPUT);
 pinMode (8, OUTPUT);
 pinMode (9, OUTPUT);
 pinMode (10, OUTPUT);
 pinMode (11, OUTPUT);*/

}  
   
void loop(){  

  //Efetua 130 leituras do sinal  
  for (int i=0; i<leituras ; i++){  
    	sinal = analogRead(pinosinal);  
    	soma = soma + sinal;  
  	}  
  nivel = soma/leituras; //Calcula o valor medio 
  //Serial.println(nivel);
  //Converte o valor lido para um valor entre 0 e 10
  mostranivel=map(nivel, 0, 500, 0, 10);
  int leds=map(nivel,34,500,2,11);
  Serial.println(mostranivel);
  for(int i=2;i<=leds;i++){
  		digitalWrite(i,HIGH);
  		delay(50); // Regula o tempo que o led fica ligado durante a subida, qnt menor melhor o sincronismo com o som tocado!
  		digitalWrite(i,LOW);
  	}
  soma=0;
  delay(50);// Regula o tempo da proxima leitura, qnt menor melhor o sincronismo com o som tocado!
}

