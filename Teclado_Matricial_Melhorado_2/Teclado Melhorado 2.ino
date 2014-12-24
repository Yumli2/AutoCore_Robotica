//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------

int linhas,colunas;


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

void LinhasColunas(byte L, byte C){
	//Linha 1
	if(L==1 && C==1){
		Serial.println("1");
	}
	if(L==1 && C==2){
		Serial.println("2");
	}
	if(L==1 && C==3){
		Serial.println("3");
	}
	if(L==1 && C==4){
		Serial.println("A");
	}
	//Linha 2
	if(L==2 && C==1){
		Serial.println("4");
	}
	if(L==2 && C==2){
		Serial.println("5");
	}
	if(L==2 && C==3){
		Serial.println("6");
	}
	if(L==2 && C==4){
		Serial.println("B");
	}
	//Linha 3
	if(L==3 && C==1){
		Serial.println("7");
	}
	if(L==3 && C==2){
		Serial.println("8");
	}
	if(L==3 && C==3){
		Serial.println("9");
	}
	if(L==3 && C==4){
		Serial.println("C");
	}
	//Linha 4
	if(L==4 && C==1){
		Serial.println("*");
	}
	if(L==4 && C==2){
		Serial.println("0");
	}
	if(L==4 && C==3){
		Serial.println("#");
	}
	if(L==4 && C==4){
		Serial.println("D");
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
			linhas=1;
			colunas=7-Col;
			LinhasColunas(linhas,colunas);
		}
		if(digitalRead(9)==LOW){
			linhas=2;
			colunas=7-Col;
			LinhasColunas(linhas,colunas);
		} 	
		if(digitalRead(8)==LOW){
			linhas=3;
			colunas=7-Col;
			LinhasColunas(linhas,colunas);
		} 	
		if(digitalRead(7)==LOW){
			linhas=4;
			colunas=7-Col;
			LinhasColunas(linhas,colunas);
		} 
		delay(50);
	}
}