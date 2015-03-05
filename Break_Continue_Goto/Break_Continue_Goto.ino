int i,j,k;
int contador=0x00;

void setup() {
 Serial.begin(9600);
 
 
//BREAK------------------------------------------------------------------------- 
/*
 for(int i=0; i<=1; i++){
    Serial.print("valir de i: ");
    Serial.println(i);
    contador++;
    break;
    
      for(int j=0; j<=1; j++){
        Serial.print("valir de j: ");
         Serial.println(j);
         contador++;
        // break;
         
          for(int k=0; k<=1; k++){
            Serial.print("valir de k: ");
             Serial.println(k);
             contador++;
             //break;
             
          }
      }
 }
*/ 
             
//CONTINUE------------------------------------------------------------------------- 
/*
 for(int i=0; i<=3; i++){
    Serial.print("valir de i: ");
    Serial.println(i);
    contador++;
   // break;
   // continue;
      for(int j=0; j<=3; j++){
        Serial.print("valir de j: ");
         Serial.println(j);
         contador++;
         //break;
         continue;
          for(int k=0; k<=2; k++){
            Serial.print("valir de k: ");
             Serial.println(k);
             contador++;
             if(k==1){
               
             }
             Serial.println("Continue");
          }
      }
 }
 */
//GOTO-------------------------------------------------------------------------

   for(int i=0; i<=4; i++){
    Serial.print("valir de i: ");
    Serial.println(i);
    contador++;
     
      for(int j=0; j<=3; j++){
        Serial.print("valir de j: ");
        Serial.println(j);
        contador++;
        if(j==2){
         goto fim;
        }
          for(int k=0; k<=2; k++){
            Serial.print("valir de k: ");
            Serial.println(k);
            contador++;
          }  
          
      }
  }

fim:
Serial.println("Fim do laco.");
Serial.println(contador);
}
 
void loop(){

}
