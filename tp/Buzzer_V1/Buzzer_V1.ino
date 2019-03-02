#include <Servo.h>

//Définition de constantes symboliques
#define BUSSER_PIN 4

void setup() 
{
  
}

void loop() {
  tone(BUZZER_PIN, 3000);
  delay(2000);
  noTone(BUZZER_PIN);
  delay(1000);

}
