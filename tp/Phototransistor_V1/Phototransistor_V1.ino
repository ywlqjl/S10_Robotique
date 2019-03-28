#include <Servo.h>
//Définition de constantes symboliques
#define DUREE 6000
#define PHOTO_TRANSISTOR 3

float D_To_A(int V_num);

void setup() 
{  
  Serial.begin(9600);
}

void loop() {

  int V_num_A3;
  //Lire la valeur numérique correspondant la tension de resistence
  V_num_A3 = analogRead(PHOTO_TRANSISTOR);

  //Print la valeur numérique
  Serial.print("A3:");
  Serial.print(V_num_A3);

  //Print la valeur de la tension de resistence
  Serial.print("  A3:  ");
  Serial.print(D_To_A(V_num_A3));
  Serial.println("Volts");
  
  delay(1000);
}


float D_To_A(int V_num){
  return (float) V_num * 5.0 /1024.0;
}
