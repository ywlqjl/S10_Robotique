#include <Servo.h>

//Définition de constantes symboliques
#define BUZZER_PIN 4
#define SERVO_DROITE_PIN 11
#define SERVO_GAUCHE_PIN 10
#define LED_GAUCHE_PIN 8
#define LED_DROITE_PIN 13

#define PHOTO_TRANSISTOR 3
#define LUMINOSITE_SEUIL 500

int val_mGauche = 0;
int val_mDroite = 0;

#define DUREE 6000
#define CHANGEMENT_DIRECTION 900
#define L 5.4

// Variables globales
Servo Servo_droite;
Servo Servo_gauche;

int largeur_implusion;
float D_To_A(int V_num);

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

  pinMode (5, INPUT); // Pour la moustache gauche
  pinMode (7, INPUT); // Pour la moustache droite
  pinMode(LED_GAUCHE_PIN, OUTPUT); 
  pinMode(LED_DROITE_PIN,OUTPUT); 
//  arret();
}

void loop() {

  int V_num_A3;
  V_num_A3 = analogRead(PHOTO_TRANSISTOR);
  Serial.print("A3 : ");
  Serial.print(V_num_A3);
  Serial.print("  A3  :  ");
  Serial.print(D_To_A(V_num_A3));
  Serial.println("Volts");
  
  delay(100);
  Strategie_robot(V_num_A3);
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
//  delay (duree_deplacement);
}

void Recule_Droite(){
  Servo_droite.writeMicroseconds(1550); 
  Servo_gauche.writeMicroseconds(1300); 
//  delay (duree_deplacement);
}

void Ralentir(){
  Servo_droite.writeMicroseconds(1400); 
  Servo_gauche.writeMicroseconds(1600); 
  delay(1000);
  Servo_droite.writeMicroseconds(1450); 
  Servo_gauche.writeMicroseconds(1550); 
  delay (1000);
  Servo_droite.writeMicroseconds(1480); 
  Servo_gauche.writeMicroseconds(1520); 
  delay (1000);
}

void Tourner(int temps){
  Servo_droite.writeMicroseconds(1300); 
  Servo_gauche.writeMicroseconds(1300); 
  delay(temps);
}

void Strategie_robot(int V_num){

  val_mGauche = digitalRead(5);
  val_mDroite = digitalRead(7);
  digitalWrite(LED_GAUCHE_PIN, 1-val_mGauche); 
  digitalWrite(LED_DROITE_PIN, 1-val_mDroite);  

  //Définir des actions selon l'état de moustache

  //Si la luminosité est faible, le robot continue à avancer;
  //Si la luminosité est importante, le robot s'immobilise.
  if (V_num >= LUMINOSITE_SEUIL){ //Clair
    Ralentir();
    arret2();
    Tourner(CHANGEMENT_DIRECTION);
  }
  else{
      
      if(val_mGauche == 1 && val_mDroite == 1 ){
        Avance();
      }
      else if(val_mGauche == 0 && val_mDroite == 1){
        Recule_Droite();
        //degree: 360
        delay(10500);
        Tourner(CHANGEMENT_DIRECTION);
      }
      else if(val_mDroite == 0 && val_mGauche == 1){
        Recule_Gauche();
        //degree: 30
        delay(1000);
      }
      else if(val_mDroite == 0 && val_mGauche == 0){ 
      Recule();
      delay(2000);
      Tourner(CHANGEMENT_DIRECTION);
      }
  }
}

float D_To_A(int V_num){
  return (float) V_num * 5.0 /1024.0;
}

//calculer le degre
float cal_degree(float v_d, float v_g, float degre){

  float v = (v_d + v_g) /2; //Vitesse de robot: m/s
  float p = L * (v_d + v_g) / (v_d - v_g); //Rayon de tourne: m
  if(p >=0){
    p = p;
  }
  else{
    p = -p;
  }
  float w = v/p; //Vitesse angulaire: rad/s
  float t = degre / (57.3 * w ) ; // temps de tourne : s
  return t;
}
