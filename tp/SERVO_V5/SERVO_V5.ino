#include <Servo.h>
//Définition de constantes symboliques
#define SERVO_GAUCHE_PIN 11
#define SERVO_DROIT_PIN 10
#define T1_1 1300
#define T1_2 1700
#define T1_3 1500

// Variables globales
Servo Servo_droit;
Servo Servo_gauche;

void setup() 
{
  Servo_droit.attach(SERVO_DROIT_PIN);  
  Servo_gauche.attach(SERVO_GAUCHE_PIN);

  //1. Faire tourner les deux servo moteurs dans le sens horaire pendant 3s ;
  Servo_droit.writeMicroseconds (T1_1);
  Servo_gauche.writeMicroseconds (T1_1);
  delay (3000);
  //2. Faire tourner les deux servo moteurs dans le sens trigonométrique pendant 2.5s
  Servo_droit.writeMicroseconds (T1_2);
  Servo_gauche.writeMicroseconds (T1_2);
  //3. Arrêter les deux servo moteurs.
  delay (2500);
  
//  Servo_droit.writeMicroseconds (T1_3);
//  Servo_gauche.writeMicroseconds (T1_3);
    Servo_droit.detach();
    Servo_gauche.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
}
