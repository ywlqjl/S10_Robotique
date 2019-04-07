#define LED_pin13 13
#define LED_pin12 12

int i;
long int tempo;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    
    pinMode(LED_pin12, OUTPUT);  //Broche 12 en sortie
    pinMode(LED_pin13, OUTPUT);  //Broche 12 en sortie

    digitalWrite(LED_pin12, LOW);  //Broche 12 LED étiente
    digitalWrite(LED_pin13, HIGH);  //Broche 13 LED allumée

}

void loop() {
  // put your main code here, to run repeatedly:
  
      digitalWrite(LED_pin12, HIGH);
      digitalWrite(LED_pin13, LOW);
      
      Serial.println("LED 12 etat haut");
      delay(1000);
      
      digitalWrite(LED_pin13, HIGH);
      digitalWrite(LED_pin12, LOW);
      Serial.println("LED 12 etat bas");
      delay(1000);  //Temporisation


}
