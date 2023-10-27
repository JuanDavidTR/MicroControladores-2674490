const int pinRojo = 7;
const int pinAmarillo = 6;
const int pinVerde = 5;
const int pinBotonParo = 11;
const int pinBotonMantenimiento = 10;
const int pinPotenciometro = A0;

int contadorBombilloRojo = 0;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotonParo, INPUT_PULLUP);
  pinMode(pinBotonMantenimiento, INPUT_PULLUP);
  Serial.begin(9600);  // Inicializar la comunicación serial a 9600 bps
}

void loop() {
  contadorBombilloRojo++;
    Serial.print("Bombillo rojo encendido. Contador: ");
    Serial.println(contadorBombilloRojo);
  // Leer el valor del potenciómetro para ajustar los tiempos del semáforo
  int valorPotenciometro = analogRead(pinPotenciometro);

  // Ciclo del semáforo con tiempos ajustados por el potenciómetro
  digitalWrite(pinRojo, HIGH);
  delay(500 / (valorPotenciometro / 1023.0));

  digitalWrite(pinAmarillo, HIGH);
  delay(100 / (valorPotenciometro / 1023.0));
  digitalWrite(pinRojo, LOW);

  digitalWrite(pinVerde, HIGH);
  delay(300 / (valorPotenciometro / 1023.0));
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  // Amarillo intermitente durante 15 segundos o hasta presionar el botón de mantenimiento
  int tiempoAmarilloIntermitente = 15000 / (valorPotenciometro / 1023.0);
  unsigned long tiempoInicioAmarillo = millis();

  while (millis() - tiempoInicioAmarillo < tiempoAmarilloIntermitente && digitalRead(pinBotonMantenimiento) == HIGH) {
    digitalWrite(pinAmarillo, HIGH);
    delay(275 / (valorPotenciometro / 1023.0));
    digitalWrite(pinAmarillo, LOW);
    delay(275 / (valorPotenciometro / 1023.0));
  }

  digitalWrite(pinAmarillo, LOW);

  // Detener el ciclo al presionar el botón de paro
  while (digitalRead(pinBotonParo) == HIGH) {
    
  
  }
}