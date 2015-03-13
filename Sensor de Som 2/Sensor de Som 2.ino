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
ledsledsleds

}  
   
void loop(){  

  //Efetua 100 leituras do sinal  
  for (int i=0; i<leituras ; i++){  
    	sinal = analogRead(pinosinal);  
    	soma = soma + sinal;  
  	}  
  nivel = soma/leituras; //Calcula o valor medio 
  //Serial.println(nivel);
  //Converte o valor lido para um valor entre 0 e 10

  mostranivel=map(nivel, 0, 500, 0, 10);
  int leds=map(nivel,0,1000,2,11);
  Serial.println(mostranivel);
  if(leds<11){
    for(int i=leds;i>=2;i--){
  	   	digitalWrite(i,HIGH);
  		  delay(50); 
  		  digitalWrite(i,LOW);
    }	 
  }
  soma=0;
  delay(50);// Regula o tempo da proxima leitura, qnt menor melhor o sincronismo com o som tocado!
}

