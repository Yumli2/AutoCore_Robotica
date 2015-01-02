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
	zero();
	delay(500);

	um();
	delay(500);
	
	dois();
	delay(500);

	tres();
	delay(500);
	
	quatro();
	delay(500);

	cinco();
	delay(500);
	
	seis();
	delay(500);

	sete();
	delay(500);
	
	oito();
	delay(500);

	nove();
	delay(500);
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
