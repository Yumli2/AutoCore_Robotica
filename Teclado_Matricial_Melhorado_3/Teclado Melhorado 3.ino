//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------

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
	Serial.print("Digito");
	Serial.print("\t\t\t");
	Serial.println("Endereco Matricial");
}

void LinhasColunas(byte L, byte C){
		//Linha 1
	if(L==1 && C==1){
		Serial.print("1");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 1 x Coluna 1");
	}
	if(L==1 && C==2){
		Serial.print("2");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 1 x Coluna 2");
	}
	if(L==1 && C==3){
		Serial.print("3");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 1 x Coluna 3");
	}
	if(L==1 && C==4){
		Serial.print("A");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 1 x Coluna 4");
	}
	//Linha 2
	if(L==2 && C==1){
		Serial.print("4");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 2 x Coluna 1");
	}
	if(L==2 && C==2){
		Serial.print("5");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 2 x Coluna 2");
	}
	if(L==2 && C==3){
		Serial.print("6");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 2 x Coluna 3");
	}
	if(L==2 && C==4){
		Serial.print("B");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 2 x Coluna 4");
	}
	//Linha 3
	if(L==3 && C==1){
		Serial.print("7");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 3 x Coluna 1");
	}
	if(L==3 && C==2){
		Serial.print("8");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 3 x Coluna 2");
	}
	if(L==3 && C==3){
		Serial.print("9");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 3 x Coluna 3");
	}
	if(L==3 && C==4){
		Serial.print("C");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 3 x Coluna 4");
	}
	//Linha 4
	if(L==4 && C==1){
		Serial.print("*");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 4 x Coluna 1");
	}
	if(L==4 && C==2){
		Serial.print("0");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 4 x Coluna 2");
	}
	if(L==4 && C==3){
		Serial.print("#");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 4 x Coluna 3");
	}
	if(L==4 && C==4){
		Serial.print("D");
		Serial.print("\t\t\t\t");
		Serial.println("Linha 4 x Coluna 4");
	}
}

void loop() {

	for(int Col=6; Col>=3; Col--){
		digitalWrite(6, HIGH);
		digitalWrite(5, HIGH);
		digitalWrite(4, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(Col,LOW);
		if(digitalRead(10)==LOW){
			LinhasColunas(1,7-Col);
		}
		if(digitalRead(9)==LOW){
			LinhasColunas(2,7-Col);
		} 	
		if(digitalRead(8)==LOW){
			LinhasColunas(3,7-Col);
		} 	
		if(digitalRead(7)==LOW){
			LinhasColunas(4,7-Col);
		} 
		delay(80);
	}
}
