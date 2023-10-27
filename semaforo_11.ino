const int pinRojo = 7;
const int pinAmarillo = 6;
const int pinVerde = 5;
const int pinBotonParo = 11;
const int pinBotonMantenimiento = 10;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotonParo, INPUT_PULLUP);
  pinMode(pinBotonMantenimiento, INPUT_PULLUP);
}

void loop() {
  // Ciclo del semáforo
  digitalWrite(pinRojo, HIGH);
  delay(5000);

  digitalWrite(pinAmarillo, HIGH);
  delay(1000);
  digitalWrite(pinRojo, LOW);

  digitalWrite(pinVerde, HIGH);
  delay(3000);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  // Amarillo intermitente durante 15 segundos o hasta presionar el botón de mantenimiento
  int tiempoAmarilloIntermitente = 15000;
  unsigned long tiempoInicioAmarillo = millis();

  while (millis() - tiempoInicioAmarillo < tiempoAmarilloIntermitente && digitalRead(pinBotonMantenimiento) == HIGH) {
    digitalWrite(pinAmarillo, HIGH);
    delay(275);
    digitalWrite(pinAmarillo, LOW);
    delay(275);
  }

  digitalWrite(pinAmarillo, LOW);

  // Detener el ciclo al presionar el botón de paro
  while (digitalRead(pinBotonParo) == HIGH) {
    // Esperar a que el botón de paro sea presionado
  }
}