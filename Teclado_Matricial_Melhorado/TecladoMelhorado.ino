//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------

int linhas,colunas,LC;


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

	for(int Col=6; Col>=3; Col--){
		digitalWrite(6, HIGH);
		digitalWrite(5, HIGH);
		digitalWrite(4, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(Col,LOW);
		if(digitalRead(10)==LOW){
			linhas=1;
			colunas=7-Col;
			Serial.print(linhas);
			Serial.print(",");
			Serial.println(colunas);
		}
		if(digitalRead(9)==LOW){
			linhas=2;
			colunas=7-Col;
			Serial.print(linhas);
			Serial.print(",");
			Serial.println(colunas);
		} 	
		if(digitalRead(8)==LOW){
			linhas=3;
			colunas=7-Col;
			Serial.print(linhas);
			Serial.print(",");
			Serial.println(colunas);
		} 	
		if(digitalRead(7)==LOW){
			linhas=4;
			colunas=7-Col;
			Serial.print(linhas);
			Serial.print(",");
			Serial.println(colunas);
		} 

		delay(100);
	}
}