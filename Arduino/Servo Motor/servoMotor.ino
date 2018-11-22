#include <Stepper.h> 
// ---------------------- VARIAVEIS GLOBAIS -----------------------------------//
short option=-1;
const int stepsPerRevolution = 2048; 
// ---------------------- INSTANCIAÇÃO DO OBJETO STEPPER ----------------------//
Stepper myStepper(stepsPerRevolution, 8,10,9,11); 
// ----------------------- PROGRAMA PRINCIPAL SETUP ---------------------------// 
void setup() { 
 Serial.begin(9600);
 myStepper.setSpeed(17.5); // MAX 17.5 RPM - MIN 1
} 
// ----------------------- PROGRAMA PRINCIPAL LOOP ---------------------------// 
void loop() {
  while(Serial.available()>0){
    String comando = leStringSerial();
    if(comando.substring(0, 5)=="FREE_")  {
      option=0;
      //ADICIONAR AQUI PARA SALVAR O COMANDO FREE_ NA EPROOM QUANDO CHAMADO
      setVelocidade(comando.substring(5, 7).toInt());
    }//IF FREE_
    else if(comando.substring(0, 6)=="ANGLE_") {
      option=1;
      //ADICIONAR AQUI PARA SALVAR O COMANDO ANGLE_ NA EPROOM QUANDO CHAMADO
      angle(comando.substring(6,10).toInt());
    }//ELSE IF ANGLE
    else if(comando=="READ_LOG") {
      Serial.println("log");
      //CHAMADA DO COMANDO PARA LISTAR O QUE ESTÁ SALVA NA EPROOM
    }
  }//while inicial
  while(!(Serial.available()>0)&&option==0){ //entra somente se FREE esta selecionado e sai sempre que recebe algo na Serial
    myStepper.step(5.6888);                //avança grau por grau -- caso aja necessidade de uma rotação negativa, usar um if antes de setVelocidade e salvar em uma flag caso for negativo, posteriormente adicionar a condição 
  }                                        //da flag aqui com o mesmo valor mas negativo(-5.6888)
}
// ------------------ FUNÇÕES -------------------------- //
void setVelocidade(int velocidade){
  if(velocidade>17)
    myStepper.setSpeed(17);
  else if(velocidade<1)
    myStepper.setSpeed(1);
  else myStepper.setSpeed(velocidade);
}

String leStringSerial(){
  String conteudo = "";
  char caractere;
  while(Serial.available() > 0) {
    caractere = Serial.read();
    if (caractere != '\n'){
      conteudo.concat(caractere);
    }
    delay(10);
  }
  return conteudo;
}

void angle(int ang) {
  delay(1000);
  if(ang>360)
  ang=360;
  else if(ang<-360)
  ang=-360;         //se quiser, nao há a necessidade dessas condições, atualmente limito o servo a girar no maximo 360º por vez.
  float steps=5.68888889*ang;
  Serial.println(steps);
  myStepper.step(steps);
}
