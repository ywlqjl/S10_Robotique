#include <Servo.h>

//Définition de constantes symboliques
#define BUZZER_PIN 4
#define SERVO_DROIT_PIN 11
#define SERVO_GAUCHE_PIN 10
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
  
  Serial.begin(9600);
  Servo_gauche.attach(SERVO_GAUCHE_PIN);  
  Servo_gauche.writeMicroseconds (1500);
  Servo_droit.attach(SERVO_DROIT_PIN);  
  Servo_droit.writeMicroseconds (1500);
  Recule_Droite(5000);
  arret();
  
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


void Recule (int duree_deplacement) 
{
  Servo_droit.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (duree_deplacement);
}

void Gauche (int duree_deplacement) 
{
  Servo_droit.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (duree_deplacement);
}

void Droite (int duree_deplacement) 
{
  Servo_droit.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1700); 
  delay (duree_deplacement);
}

void Avance_Droite(int duree_deplacement){
  Servo_droit.writeMicroseconds(1450); 
  Servo_gauche.writeMicroseconds(1700); 
  delay (duree_deplacement);
}

void Avance_Gauche(int duree_deplacement){
  Servo_droit.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1550); 
  delay (duree_deplacement);
}

void Recule_Gauche(int duree_deplacement){
  Servo_droit.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1450); 
  delay (duree_deplacement);
}

void Recule_Droite(int duree_deplacement){
  Servo_droit.writeMicroseconds(1550); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (duree_deplacement);
}
