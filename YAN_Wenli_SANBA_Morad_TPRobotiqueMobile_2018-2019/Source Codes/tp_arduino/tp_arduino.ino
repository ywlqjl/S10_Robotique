#define LED_pin13 13
#define LED_pin12 12
#define TEMPO_High 500
#define TEMPO_Low 750

int i;
long int tempo;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED_pin12, OUTPUT);
    pinMode(LED_pin13, OUTPUT);
    digitalWrite(LED_pin13, LOW);
    digitalWrite(LED_pin12, LOW);

//version 1
/*
    for(i = 0; i < 10; i++)
    {
      Serial.print("\t : ");
      Serial.println(i);
      digitalWrite(LED_pin, HIGH);
      Serial.println("LED etat haut");
      for(tempo = 0; tempo< TEMPO_High; tempo++);
      digitalWrite(LED_pin, LOW);
      Serial.println("LED etat bas");
      for(tempo = 0; tempo< TEMPO_High; tempo++);

    }
*/

//version 2
/*
    for(i = 0; i < 10; i++)
    {
      Serial.print("\t : ");
      Serial.println(i);
      digitalWrite(LED_pin, HIGH);
      Serial.println("LED etat haut");
      delay(TEMPO_High);
      digitalWrite(LED_pin, LOW);
      Serial.println("LED etat bas");
      delay(TEMPO_Low);
    }
*/
}

void loop() {
  // put your main code here, to run repeatedly:
  
      digitalWrite(LED_pin, HIGH);
      Serial.println("LED etat haut");
      delay(TEMPO_High);
      digitalWrite(LED_pin, LOW);
      Serial.println("LED etat bas");
      delay(TEMPO_Low);


}
