
void setup() {

	Serial.begin(9600);
	
	pinMode(10,INPUT_PULLUP);//Linhas
	pinMode(9,INPUT_PULLUP); //Linhas
	pinMode(8,INPUT_PULLUP); //Linhas
	pinMode(7,INPUT_PULLUP); //Linhas

	pinMode(6, OUTPUT); //Colunas
	pinMode(5, OUTPUT); //Colunas
	pinMode(4, OUTPUT); //Colunas
	pinMode(3, OUTPUT); //Colunas

	Serial.println("Aperte a tecla desejada: ");

}

void loop() {

	//Leitura da 1ª linha
	
	digitalWrite(6, LOW);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);

	if(digitalRead(10)==LOW){
		Serial.println("Tecla 1");
	}

	digitalWrite(6, HIGH);
	digitalWrite(5, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);
		
	if(digitalRead(10)==LOW){
		Serial.println("Tecla 2");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, LOW);
	digitalWrite(3, HIGH);
		
	if(digitalRead(10)==LOW){
		Serial.println("Tecla 3");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, LOW);
		
	if(digitalRead(10)==LOW){
		Serial.println("Tecla A");
	} 	
	// fim da leitura da 1ª linha

	//Leitura da 2ª linha
	
	digitalWrite(6, LOW);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);

	if(digitalRead(9)==LOW){
		Serial.println("Tecla 4");
	}

	digitalWrite(6, HIGH);
	digitalWrite(5, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);
		
	if(digitalRead(9)==LOW){
		Serial.println("Tecla 5");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, LOW);
	digitalWrite(3, HIGH);
		
	if(digitalRead(9)==LOW){
		Serial.println("Tecla 6");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, LOW);
		
	if(digitalRead(9)==LOW){
		Serial.println("Tecla B");
	} 	
	// fim da leitura da 2ª linha

	//Leitura da 3ª linha
	
	digitalWrite(6, LOW);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);

	if(digitalRead(8)==LOW){
		Serial.println("Tecla 7");
	}

	digitalWrite(6, HIGH);
	digitalWrite(5, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);
		
	if(digitalRead(8)==LOW){
		Serial.println("Tecla 8");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, LOW);
	digitalWrite(3, HIGH);
		
	if(digitalRead(8)==LOW){
		Serial.println("Tecla 9");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, LOW);
		
	if(digitalRead(8)==LOW){
		Serial.println("Tecla C");
	} 	
	// fim da leitura da 3ª linha

	//Leitura da 4ª linha
	
	digitalWrite(6, LOW);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);

	if(digitalRead(7)==LOW){
		Serial.println("Tecla *");
	}

	digitalWrite(6, HIGH);
	digitalWrite(5, LOW);
	digitalWrite(4, HIGH);
	digitalWrite(3, HIGH);
		
	if(digitalRead(7)==LOW){
		Serial.println("Tecla 0");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, LOW);
	digitalWrite(3, HIGH);
		
	if(digitalRead(7)==LOW){
		Serial.println("Tecla #");
	} 	

	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(4, HIGH);
	digitalWrite(3, LOW);
		
	if(digitalRead(7)==LOW){
		Serial.println("Tecla D");
	} 	
	// fim da leitura da 4ª linha

	delay(200);

}

