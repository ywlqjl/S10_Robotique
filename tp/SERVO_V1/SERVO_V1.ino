#include <Servo.h>

#define TEMPO_T 20  // Cas2:200  Cas3: 20
#define TEMPO_T1 1500  // Cas2:15   Cas3: 2

// Variables globales
Servo Servo_droit;
Servo Servo_gauche;


void setup() {
  // put your setup code here, to run once:
  
    Servo_gauche.attach (11);
    Servo_droit.attach (10);
    //équilibrer
    Servo_gauche.writeMicroseconds (TEMPO_T1);
    Servo_droit.writeMicroseconds (TEMPO_T1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
