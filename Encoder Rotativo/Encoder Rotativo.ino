#define encoder0PinA 2
#define encoder0PinB 3
         
long lastDebounceTime = 0;
long debounceDelay = 100;
 
volatile int encoder0Pos = 0;
 
void setup() {
 
 
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
 
   // encoder pin on interrupt 0 - pin 2
  attachInterrupt(0, encoder, CHANGE);
 
  Serial.begin (9600);
  Serial.println("Inicio");                // a personal quirk
 
}
 
void loop(){
// do some stuff here - the joy of interrupts is that they take care of themselves
}
 
 void encoder(){
  //Faz a leitura nos canais digitais das duas saidas do sinal A e B
  int reading1 = digitalRead(encoder0PinA);
  int reading2 = digitalRead(encoder0PinB);
  Serial.println("leitura de um ciclo.");
  Serial.print(reading1);
   Serial.print("/");
  Serial.println(reading2);
  //Faz as comparações das leituras independente se igual ou diferente, para obrigar a cair, nessa atribuição.
  if ( reading1==reading2) {
    // reset the debouncing timer
    lastDebounceTime = micros();
    delay(1);
  }
 
  if ((micros() - lastDebounceTime) > debounceDelay) {
   
    if (reading1 == reading2) {
      Serial.println(encoder0Pos);
      encoder0Pos++;
    }
    else{
      Serial.println(encoder0Pos);
      encoder0Pos--;
    }
  }
}
