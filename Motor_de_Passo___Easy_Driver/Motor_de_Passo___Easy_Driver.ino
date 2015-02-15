// Motor de Passo.ino

// Pinos conectados ao Step e Dir do Easydriver
int pino_passo = 5;
int pino_direcao = 4;
char sentido;

int direcao = 1;

// Quantidade de passos para uma volta completa
// Ajuste de acordo com o seu motor
int passos_motor = 360;

void setup() 
{
  // Define os pinos como saida
  Serial.begin(9600);
  pinMode(pino_passo, OUTPUT);
  pinMode(pino_direcao, OUTPUT);
}

void loop()
{
  
  boolean flag=true;
  if(flag)
  {
    while(Serial.available())
    {
      sentido = Serial.read();
      flag=false;
    }
  }
  // Define a direcao de rotacao
  if(sentido=='D' || sentido=='d')
  {
    direcao = 1;
    digitalWrite(pino_direcao, direcao);
    for (int p=0 ; p < passos_motor; p++)
    {
      digitalWrite(pino_passo, 1);
      delay(1);
      digitalWrite(pino_passo, 0);
      delay(1);
    }
    delay(1000); //altere o tempo de acionamento para aumentar a velovidade de rotação.
  }
  else if(sentido=='E' || sentido=='e')
  {
    // Inverte a direcao de rotacao
    direcao = 0;
    digitalWrite(pino_direcao, direcao);
    for (int p=0 ; p < passos_motor; p++)
    {
      digitalWrite(pino_passo, 1);
      delay(1);
      digitalWrite(pino_passo, 0);
      delay(1);
    }
    delay(200); //altere o tempo de acionamento para aumentar a velovidade de rotação.
  }
}


