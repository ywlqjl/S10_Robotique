#include <Servo.h>
//Définition de constantes symboliques
#define BUZZER_PIN 4
#define DUREE 6000
#define PHOTO_TRANSISTOR 3
#define LUMINOSITE_SEUIL 700

float D_To_A(int V_num);

float D_To_A(int V_num){
  return (float) V_num * 5.0 /1024.0;
}


void setup() 
{
//  tone(BUZZER_PIN, 3000);
//  delay(1000);
//  noTone(BUZZER_PIN);
  
  Serial.begin(9600);

  
}

void loop() {

  int V_num_A3;
  V_num_A3 = analogRead(PHOTO_TRANSISTOR);
  Serial.print("A3 : ");
  Serial.print(V_num_A3);
  Serial.print("  A3  :  ");
  Serial.print(D_To_A(V_num_A3));
  Serial.println("Volts");

  if (V_num_A3 >= LUMINOSITE_SEUIL){ //Sombre
    Avance();
  }
  else{
    arret();
  }
  delay(1000);
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
//  delay (duree_deplacement);
}



long rcTime(int pin){
  unsigned long int time;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(1);
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
  time = micros();
  while(digitalRead(pin));
  time = micros()-time;
  return time;
}
