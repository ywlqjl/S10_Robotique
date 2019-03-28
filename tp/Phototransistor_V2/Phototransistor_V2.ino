#include <Servo.h>
//Définition de constantes symboliques
#define BUZZER_PIN 4
#define DUREE 6000
#define SERVO_DROITE_PIN 11
#define SERVO_GAUCHE_PIN 10
#define PHOTO_TRANSISTOR 3
//On a définit un bon seuil voltage numérique = 700
#define LUMINOSITE_SEUIL 700
// Variables globales
Servo Servo_droite;
Servo Servo_gauche;

float D_To_A(int V_num);

float D_To_A(int V_num){
  return (float) V_num * 5.0 /1024.0;
}


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

  
}

void loop() {
  int V_num_A3;
  V_num_A3 = analogRead(PHOTO_TRANSISTOR);
  Serial.print("A3 : ");
  Serial.print(V_num_A3);
  Serial.print("  A3  :  ");
  Serial.print(D_To_A(V_num_A3));
  Serial.println("Volts");
  my_fonction(V_num_A3);

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

void arret2 (void) 
{
  Servo_droite.writeMicroseconds(1500); 
  Servo_gauche.writeMicroseconds(1500); 
}

void Recule () 
{
  Servo_droite.writeMicroseconds(1700); 
  Servo_gauche.writeMicroseconds(1300); 
//  delay (duree_deplacement);
}

void Ralentir(){
  Servo_droite.writeMicroseconds(1550); 
  Servo_gauche.writeMicroseconds(1450); 
}

//Si la luminosité est faible, le robot continue à avancer;
//Si la luminosité est importante, le robot s'immobilise.
void my_fonction(int V_num){

  if (V_num <= LUMINOSITE_SEUIL){ //Sombre
    Avance();
  }
  else{
    arret2();
//      Ralentir();
  }
}
