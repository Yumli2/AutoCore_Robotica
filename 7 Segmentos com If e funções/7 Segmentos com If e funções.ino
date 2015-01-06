// 7 Segmentos com If e funções.ino
//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------
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
	for(int i=0; i<=9; i++){
	    if(i==0){
	    	zero();
	    }
	    else if(i==1){
	    	um();
	    }
	    else if(i==2){
	    	dois();
	    }
	    else if(i==3){
	    	tres();
	    }
	    else if(i==4){
	    	quatro();
	    }
	    else if(i==5){
	    	cinco();
	    }
	    else if(i==6){
	    	seis();
	    }
	    else if(i==7){
	    	sete();
	    }
	    else if(i==8){
	    	oito();
	    }
	    else if(i==9){
	    	nove();
	    }
	    delay(500);
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

