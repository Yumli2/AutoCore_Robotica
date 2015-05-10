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
//definição dos dígitos
#define d1 9
#define d2 10
#define d3 11
#define d4 12
//=========================================================================================================================
//Definição das Chaves
#define sensor1 50
#define sensor2 52
//=========================================================================================================================
//Outras definições
#define del 2000//regula o tempo
int x = 200; //Define a velocidade da contagem
short int ch1,ch2;
short int n=0,m=0,tempo=0,tempo2=0,i=0,j=0,h=1,tempoInterno=0;
boolean flag= true;
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
   if (digitalRead(sensor1)==HIGH && j==0){ //O carro passou pelo sensor
        i=0;
        chave1();
  }   
  if (digitalRead(sensor1)==HIGH && j==1){ //Quando o segundo ou demais carros passa pelo sensor
  tempoInterno=0;  

   while((tempo>0) || (flag==true)){ 
      while(digitalRead(sensor2)==LOW ){
        clearLEDs();
        pickDigit(1);
        pickNumber(tempo/x%10);
        delayMicroseconds(del);
      
        clearLEDs();
        pickDigit(2);
        pickNumber((tempo/x/10)%10);
        delayMicroseconds(del);
        if(tempo>0){
          tempo--; // incrementa n
        }
        tempoInterno+=1; // Tem que ser tempoInterno +1 por que Tempo-- vai decrementar o tempo 1000 por exemplo de um a um
        if(digitalRead(sensor2)!=LOW){
          tempo=0;
          goto para;
        }
      }
      para:
      flag=false;
    } 
    Serial.print("tempo: ");
    Serial.println(tempo);
    Serial.print("tempo Interno: ");
    Serial.println(tempoInterno);
    tempo= tempoInterno;
    ch1=LOW;
    
  }
}
//=========================================================================================================================
//=========================================================================================================================
// teste logico das chaves  
void chave1(){
  while (digitalRead(sensor2)==LOW){
        Serial.print(n);
        Serial.print(" - ");
        Serial.print(i);
        Serial.println(" Segundos");
        i++;
        n = n+200; // Incrementa n
        delay(1000); //Segundos
      }
      ch1=LOW;
      j=1;
      tempo += n;
        //chave2();
}
void chave1(){
  while (digitalRead(sensor2)==LOW){
        Serial.print(n);
        Serial.print(" - ");
        Serial.print(i);
        Serial.println(" Segundos");
        i++;
        n = n+200; // Incrementa n
        delay(1000); //Segundos
      }
      ch1=LOW;
      j=1;
      tempo += n;
        //chave2();
}
//=========================================================================================================================
//=========================================================================================================================
// subrotina para multiplexar os dígitos do display
void pickDigit(int x){
  digitalWrite(d1, HIGH);// valor HIGH no pino desabilita o dígito
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
  
  switch(x){ // cria uma estrutura switch, tendo como entrada
            // o número do display a ser habilitado
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
//=========================================================================================================================
//=========================================================================================================================
// subrotina para acender um determinado número no display
int pickNumber(int x){
  switch(x){ // cria uma estrutura switch para seleção
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
// subrotina para apagar todos os segmentos
void clearLEDs()
{
  digitalWrite(a, LOW); // valor low no pino, apaga segmento
  digitalWrite(b, LOW);
  digitalWrite(cc, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  //digitalWrite(p, LOW);
}
//=========================================================================================================================
//=========================================================================================================================
// mostra número sero no display
void zero()
{
  digitalWrite(a, HIGH); // valor HIGH no pino, acende segmento
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void two()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(cc, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void three()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void four()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void five()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(cc, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
// Fim da Compilação