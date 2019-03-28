#include <Servo.h>

//Définition de constantes symboliques
#define BUZZER_PIN 4
#define SERVO_DROITE_PIN 11
#define SERVO_GAUCHE_PIN 10
#define LED_GAUCHE_PIN 8
#define LED_DROITE_PIN 13
int val_mGauche = 0;
int val_mDroite = 0;


#define DUREE 6000


// Variables globales
Servo Servo_droite;
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
  Servo_droite.attach(SERVO_DROITE_PIN);  
  Servo_droite.writeMicroseconds (1500);
//  Recule_Droite(5000);
  //Avance(1000);
  
//  arret();
}

void loop() {
  delay(100);
  Ma_fonction();
  delay(100);
}



void Avance () 
{
  Servo_droite.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1700); 
//  delay (duree_deplacement);
}

void arret (void) 
{
  Servo_droite.detach (); 
  Servo_gauche.detach ();
}


void Recule () 
{
  Servo_droite.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (2000);
}

void Gauche (int duree_deplacement) 
{
  Servo_droite.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (duree_deplacement);
}

void Droite (int duree_deplacement) 
{
  Servo_droite.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1700); 
  delay (duree_deplacement);
}

void Avance_Droite(int duree_deplacement){
  Servo_droite.writeMicroseconds(1450); 
  Servo_gauche.writeMicroseconds(1700); 
  delay (duree_deplacement);
}

void Avance_Gauche(int duree_deplacement){
  Servo_droite.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1550); 
  delay (duree_deplacement);
}

void Recule_Gauche(){
  Servo_droite.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1450); 
  delay (2000);
}

void Recule_Droite(){
  Servo_droite.writeMicroseconds(1550); 
  Servo_gauche.writeMicroseconds(1300); 
  delay (2000);
}

void Ma_fonction(){

  pinMode (5, INPUT); // Pour la moustache gauche
  pinMode (7, INPUT); // Pour la moustache droite
  pinMode(LED_GAUCHE_PIN, OUTPUT); 
  pinMode(LED_DROITE_PIN,OUTPUT); 
  val_mGauche = digitalRead(5);
  val_mDroite = digitalRead(7);

  Serial.print("Gauche:");
  Serial.println(val_mGauche);
  Serial.print("Droite:");
  Serial.println(val_mDroite);

  //Allumer les deux LED correspondantes
  digitalWrite(LED_GAUCHE_PIN, 1-val_mGauche); 
  digitalWrite(LED_DROITE_PIN, 1-val_mDroite);  
  

}
