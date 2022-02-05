#include <Servo.h>

#define SERVO 10
Servo S;

int pos = 90;
int counter = 90;
char comando;

void setup() {
 
 S.attach(SERVO);
 Serial.begin(9600);
 S.write(90);
 
}

void loop() {

  if (!Serial.available()) comando = 'C';
  
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
