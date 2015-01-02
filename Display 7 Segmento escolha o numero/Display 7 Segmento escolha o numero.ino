// Display 7 Segmento.ino

void setup() {
	Serial.begin(9600);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

}
void loop() {
	while(Serial.available()){
		char numero=Serial.read();
		switch(numero){
			case '0': zero();
			break;
			case '1': um();
			break;
			case '2': dois();
			break;
			case '3': tres();
			break;
			case '4': quatro();
			break;
			case '5': cinco();
			break;
			case '6': seis();
			break;
			case '7': sete();
			break;
			case '8': oito();
			break;
			case '9': nove();
			break;
			case '.': ponto();
			break;
			default: Serial.print("Valor informado é invalido!");
			break;
		}
	}
}
void zero(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,1);
	digitalWrite(6,1);
	digitalWrite(7,1);
	digitalWrite(8,0);
	digitalWrite(9,1);
}

void um(){
	digitalWrite(2,0);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(7,0);
	digitalWrite(8,0);
	digitalWrite(9,0);
}
void dois(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,0);
	digitalWrite(5,1);
	digitalWrite(6,1);
	digitalWrite(7,0);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void tres(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,1);
	digitalWrite(6,0);
	digitalWrite(7,0);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void quatro(){
	digitalWrite(2,0);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(7,1);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void cinco(){
	digitalWrite(2,1);
	digitalWrite(3,0);
	digitalWrite(4,1);
	digitalWrite(5,1);
	digitalWrite(6,0);
	digitalWrite(7,1);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void seis(){
	digitalWrite(2,1);
	digitalWrite(3,0);
	digitalWrite(4,1);
	digitalWrite(5,1);
	digitalWrite(6,1);
	digitalWrite(7,1);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void sete(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(7,0);
	digitalWrite(8,0);
	digitalWrite(9,0);
}
void oito(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,1);
	digitalWrite(6,1);
	digitalWrite(7,1);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void nove(){
	digitalWrite(2,1);
	digitalWrite(3,1);
	digitalWrite(4,1);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(7,1);
	digitalWrite(8,1);
	digitalWrite(9,0);
}
void ponto(){
	digitalWrite(2,0);
	digitalWrite(3,0);
	digitalWrite(4,0);
	digitalWrite(5,0);
	digitalWrite(6,0);
	digitalWrite(7,0);
	digitalWrite(8,0);
	digitalWrite(9,1);
}
