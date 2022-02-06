#include <Servo.h>

#define SERVO 10
#define SERVOY 9
Servo S;
Servo SY;

int pos = 90;
int counter = 90;

int posY = 90;
int counterY = 90;

char comando;

void setup() {
  Serial.begin(9600);
 
 S.attach(SERVO);
 S.write(90);

 SY.attach(SERVOY);
 SY.write(90);
 
}

void loop() {

  if (!Serial.available()) comando = 'Z';
  
  while (Serial.available()) {
    comando = Serial.read();
  }


  if (comando == 'A') {
   direita();
   counter = pos;
  }

 else if (comando == 'B') {
  esquerda();
  counter = pos;
  }

  else if (comando == 'C') {
   cima();
   counterY = posY;
  }

 else if (comando == 'D') {
  baixo();
  counterY = posY;
  }
}
 


void esquerda() {
 for(pos; pos<counter+1; pos++)
 {  
    S.write(pos);
    delay(50);
 }
 delay(20);
}


void direita() {
  for(pos; pos>=counter-1; pos--){
    S.write(pos);
    delay(50);
 }
 delay(20);
}


void cima() {
 for(posY; posY<counterY+1; posY++)
 {  
    SY.write(posY);
    delay(50);
 }
 delay(20);
}


void baixo() {
  for(posY; posY>=counterY-1; posY--){
    SY.write(posY);
    delay(50);
 }
 delay(20);
}
