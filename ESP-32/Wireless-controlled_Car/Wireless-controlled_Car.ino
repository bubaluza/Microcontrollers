// ----------- PIN DEFITIONS ------------
#define MotorRightControl1 15
#define MotorRightControl2 2
#define MotorLeftControl1 21
#define MotorLeftControl2 19

// ----------- VAR ------------------
int velocity = 40;                                // portentage of speed that are used on PWM 
// ----------- FUNCTIONS DECLARATION ------------
void goAhead();
void goBack();
void turnLeft();
void turnRight();
void Stop();


void setup() {
  Serial.begin(9600);
  ledcAttachPin(MotorRightControl1, 1);
  ledcAttachPin(MotorRightControl2, 2);
  ledcAttachPin(MotorLeftControl1, 3);
  ledcAttachPin(MotorLeftControl2, 4);
  ledcSetup(1, 500, 10);
  ledcSetup(2, 500, 10);
  ledcSetup(3, 500, 10);
  ledcSetup(4, 500, 10);
  goAhead();
}
int dir=0;
void loop() {
  if(Serial.available()>0){
    dir=Serial.read();
    switch(dir){
      case '0':
        goAhead();
        break;
      case '1':
        goBack();
        break;
      case '2':
        turnLeft();
        break;
      case '3':
        turnRight();
        break;
      case '4':
        Stop();
        break;
    }
  }
  

}
// ---------- FUNCTIONS -------------------
void goAhead(){
  ledcWrite(1, map(velocity,0, 100, 0 , 1023));
  ledcWrite(2, 0);
  ledcWrite(3, map(velocity,0, 100, 0 , 1023));
  ledcWrite(4, 0);
} 

void goBack(){
  ledcWrite(1, 0);
  ledcWrite(2, map(velocity,0, 100, 0 , 1023));
  ledcWrite(3, 0);
  ledcWrite(4, map(velocity,0, 100, 0 , 1023)); 
}

void turnLeft(){
  ledcWrite(1, map(velocity,0, 100, 0 , 1023));
  ledcWrite(2, 0);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
}

void turnRight(){
  ledcWrite(1 , 0);
  ledcWrite(2 , 0);
  ledcWrite(3 , map(velocity,0, 100, 0 , 1023));
  ledcWrite(4 , 0);
}

void Stop(){
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
  ledcWrite(4, 0);
}
