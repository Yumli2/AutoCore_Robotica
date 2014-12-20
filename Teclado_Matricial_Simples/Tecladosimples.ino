#define linha1 10
#define linha2 9
#define linha3 8
#define linha4 7

#define coluna1 6
#define coluna2 5
#define coluna3 4
#define coluna4 3

void setup() {

	Serial.begin(9600);
	
	pinMode(linha1,INPUT_PULLUP);//Linha 1
	pinMode(linha2,INPUT_PULLUP); //Linha 2
	pinMode(linha3,INPUT_PULLUP); //Linha 3
	pinMode(linha4,INPUT_PULLUP); //Linha 4

	pinMode(coluna1, OUTPUT); //Coluna 1
	pinMode(coluna2, OUTPUT); //Coluna 2
	pinMode(coluna3, OUTPUT); //Coluna 3
	pinMode(coluna4, OUTPUT); //Coluna 4

	Serial.println("Aperte a tecla desejada: ");

}

void loop() {

	//Leitura da 1ª linha
	
	digitalWrite(coluna1, LOW);  //Coluna 1
	digitalWrite(coluna2, HIGH); //Coluna 2
	digitalWrite(coluna3, HIGH); //Coluna 3
	digitalWrite(coluna4, HIGH); //Coluna 4

	if(digitalRead(linha1)==LOW){
		Serial.println("Tecla 1");
	}

	digitalWrite(coluna1, HIGH); //coluna1
	digitalWrite(coluna2, LOW);  //coluna2
	digitalWrite(coluna3, HIGH); //coluna3
	digitalWrite(coluna4, HIGH); //coluna4
		
	if(digitalRead(linha1)==LOW){
		Serial.println("Tecla 2");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, LOW);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha1)==LOW){
		Serial.println("Tecla 3");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, LOW);
		
	if(digitalRead(linha1)==LOW){
		Serial.println("Tecla A");
	} 	
	// fim da leitura da 1ª linha

	//Leitura da 2ª linha

	digitalWrite(coluna1, LOW);  //Coluna 1
	digitalWrite(coluna2, HIGH); //Coluna 2
	digitalWrite(coluna3, HIGH); //Coluna 3
	digitalWrite(coluna4, HIGH); //Coluna 4

	if(digitalRead(linha2)==LOW){
		Serial.println("Tecla 4");
	}

	digitalWrite(coluna1, HIGH); //coluna1
	digitalWrite(coluna2, LOW);  //coluna2
	digitalWrite(coluna3, HIGH); //coluna3
	digitalWrite(coluna4, HIGH); //coluna4
		
	if(digitalRead(linha2)==LOW){
		Serial.println("Tecla 5");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, LOW);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha2)==LOW){
		Serial.println("Tecla 6");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, LOW);
		
	if(digitalRead(linha2)==LOW){
		Serial.println("Tecla B");
	} 	
	// fim da leitura da 2ª linha

	//Leitura da 3ª linha
	
	digitalWrite(coluna1, LOW);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, HIGH);

	if(digitalRead(linha3)==LOW){
		Serial.println("Tecla 7");
	}

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, LOW);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha3)==LOW){
		Serial.println("Tecla 8");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, LOW);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha3)==LOW){
		Serial.println("Tecla 9");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, LOW);
		
	if(digitalRead(linha3)==LOW){
		Serial.println("Tecla C");
	} 	
	// fim da leitura da 3ª linha

	//Leitura da 4ª linha
	
	digitalWrite(coluna1, LOW);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, HIGH);

	if(digitalRead(linha4)==LOW){
		Serial.println("Tecla *");
	}

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, LOW);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha4)==LOW){
		Serial.println("Tecla 0");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, LOW);
	digitalWrite(coluna4, HIGH);
		
	if(digitalRead(linha4)==LOW){
		Serial.println("Tecla #");
	} 	

	digitalWrite(coluna1, HIGH);
	digitalWrite(coluna2, HIGH);
	digitalWrite(coluna3, HIGH);
	digitalWrite(coluna4, LOW);
		
	if(digitalRead(linha4)==LOW){
		Serial.println("Tecla D");
	} 	
	// fim da leitura da 4ª linha

	delay(200);

}

