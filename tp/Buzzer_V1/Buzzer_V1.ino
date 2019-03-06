#include <Servo.h>

//Définition de constantes symboliques
#define BUZZER_PIN 4

void setup() 
{
  //générer le son par la fonction "tone()"
  tone(BUZZER_PIN, 3000);
  delay(2000);
  
  //arrêter le son par la fonction "noTone()"
  noTone(BUZZER_PIN);
  delay(1000);
}

void loop() {
  
}
