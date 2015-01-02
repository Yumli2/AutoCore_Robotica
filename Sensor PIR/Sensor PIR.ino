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
#define PIR 2

/*Para as demais notas, acesse 
http://www2.eca.usp.br/prof/iazzetta/tutor/acustica/introducao/tabela1.html
*/
 
void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
}
 
void loop() {
	
	
tone(3,SOL);
delay(5000);


noTone(3);



}