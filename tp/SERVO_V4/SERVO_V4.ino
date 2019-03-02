#include <Servo.h>

#define TEMPO_T 20  // Cas2:200  Cas3: 20
#define TEMPO_T1 1500  // Cas2:15   Cas3: 2
#define TEMPO_T2 1850 // Cas2:185  Cas3: 18

// Variables globales
Servo Servo_droit;
Servo Servo_gauche;


//
void setup() {
  // put your setup code here, to run once:

    Servo_gauche.attach (11);
    Servo_droit.attach (10);
}

void loop() {
  // put your main code here, to run repeatedly:

    //Inférieur à 1500: il tourne dans un sens
    Servo_gauche.writeMicroseconds (1300); 
    //Supérieur à 1500: il tourne dans l'autre sens
    Servo_droit.writeMicroseconds (1400);
    
}
