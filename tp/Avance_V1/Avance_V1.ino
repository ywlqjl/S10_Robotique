#include <Servo.h>

//Définition de constantes symboliques
#define BUZZER_PIN 4
#define SERVO_GAUCHE_PIN 11
#define SERVO_DROIT_PIN 10
#define DUREE 6000

// Variables globales
Servo Servo_droit;
Servo Servo_gauche;

int largeur_implusion;

void setup() 
{
  tone(BUZZER_PIN, 3000);
  delay(1000);
  noTone(BUZZER_PIN);
  
//  Serial.begin(9600);
//  Servo_droit.attach(SERVO_DROIT_PIN);  
//  Servo_droit.writeMicroseconds (1500);
  Avance(3000);

  
}

void loop() {

}



void Avance (int duree_deplacement) 
{
  Servo_droit.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1700); 
  delay (duree_deplacement);
}

void arret (void) 
{
  Servo_droit.detach (); 
  Servo_gauche.detach ();
}
