#include <Servo.h>

//Définition de constantes symboliques
#define BUSSER_PIN 4
#define SERVO_GAUCHE_PIN 11
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
  
  Serial.begin(9600)
  
  Servo_droit.attach(SERVO_DROIT_PIN);  
 
  Servo_droit.writeMicroseconds (1500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(largeur_impulsion = 1300; largeur_implusion <= 1700; largeur_implusion += 10){
    Serial.print("Largeur_implusion = ");
    Serial.println(Largeur_implusion);
    Serial.println("Appuyer sur une touche et valider");
    Serial.println("Envoi pour demarrer le servo moteur...");

    while(Serial.available() == 0);
    Serial.read();

    Serial.println("Running...");
    Servo_droit.writeMicroseconds (largeur_impulsion);
//    Servo_droit.writeMicroseconds (largeur_impulsion);
    delay(DUREE);
    Servo_droit.writeMicroseconds (1500);   
  }

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
