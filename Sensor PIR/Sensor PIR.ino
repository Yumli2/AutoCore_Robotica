//Autor: Yuri Lima Empresa: AutoCore Robotica
//Blog: http://www.autocorerobotica.blog.br/
//Loja http://www.autocorerobotica.com/
//-------------------------------------------------

// Constantes com as notas
#define DO  262
#define RE  294
#define MI  330
#define FA  349
#define SOL 392
#define LA  440
#define SI  523

/*Para as demais notas, acesse 
http://www2.eca.usp.br/prof/iazzetta/tutor/acustica/introducao/tabela1.html
*/
 
void setup() {
pinMode(3,OUTPUT);
}
 
void loop() {

tone(3,SOL);
delay(1000);
tone(3,LA);
delay(300);
tone(3,SOL);
delay(700);
tone(3,MI);
delay(1800);
tone(3,SOL);
delay(1000);
tone(3,LA);
delay(300);
tone(3,SOL);
delay(700);
tone(3,MI);
delay(1800);
tone(3,587,0.1703); //RE maior
delay(1000);
noTone(3);
delay(300);
tone(3,587,0.1703);//RE maior
delay(500);
tone(3,494,0.2025);//SI maior
delay(1800);
tone(3,523,0.1911); //DO maior
delay(1000);
noTone(3);
delay(300);
tone(3,523,0.1911);//DO maior
delay(500);
tone(3,SOL);
delay(1500);
tone(3,LA);
delay(1000);
noTone(3);
delay(300);
tone(3,LA);
delay(300);
tone(3,523,0.1911); //DO maior
delay(1000);
tone(3,494,0.2025);//SI maior
delay(600);
tone(3,LA);
delay(500);
tone(3,SOL);
delay(1000);
tone(3,LA);
delay(500);
tone(3,SOL);
delay(800);
tone(3,MI);
delay(1800);
tone(3,LA);
delay(1000);
noTone(3);
delay(300);
tone(3,LA);
delay(300);
tone(3,523,0.1911); //DO maior
delay(1200);
tone(3,494,0.2025);//SI maior
delay(600);
tone(3,LA);
delay(300);
tone(3,SOL);
delay(1000);
tone(3,LA);
delay(300);
tone(3,SOL);
delay(800);
tone(3,MI);
delay(1800);
tone(3,587,0.1703);//RE maior
delay(1300);
noTone(3);
delay(300);
tone(3,587,0.1703);//RE maior
delay(300);
tone(3,698,0.1432);//FA maior
delay(1000);
tone(3,659,0.1517);//MI maior
delay(500);
tone(3,587,0.1703);//RE maior
delay(500);
tone(3,523,0.1911); //DO maior
delay(1200);
noTone(3);
delay(300);
tone(3,523,0.1911); //DO maior
delay(300);
tone(3,659,0.1517);//MI maior
delay(1500);
tone(3,523,0.1911); //DO maior
delay(1250);
tone(3,SOL);
delay(500);
tone(3,MI);
delay(800);
tone(3,SOL);
delay(1000);
tone(3,349,0.2863); //FA
delay(500);
tone(3,294,0.3405); //RE
delay(500);
tone(3,262,0.3822); //Do
delay(2000);
noTone(3);
delay(5000);

}