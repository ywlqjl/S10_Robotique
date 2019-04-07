#define LED_pin13 13
#define LED_pin12 12
#define TEMPO_T1 150  // Cas2:15   Cas3: 2
#define TEMPO_T2 1850 // Cas2:185  Cas3: 18

int i;
long int tempo;

void setup() {
    Serial.begin(9600);
    
    pinMode(LED_pin13, OUTPUT);  //Broche 12 en sortie
    pinMode(LED_pin12, OUTPUT);  //Broche 12 en sortie
    digitalWrite(LED_pin13, LOW);  //Broche 13 LED éteinte
    digitalWrite(LED_pin12, LOW);  //Broche 13 LED éteinte
}

void loop() {
  // put your main code here, to run repeatedly:
  
      digitalWrite(LED_pin13, HIGH);
      digitalWrite(LED_pin12, HIGH);

      Serial.println("LED 13,12 etat haut");
      delay(TEMPO_T1);
      
      digitalWrite(LED_pin13, LOW);
      digitalWrite(LED_pin12, LOW);

      Serial.println("LED 13,12 etat bas");
      delay(TEMPO_T2);  //Temporisation

}
