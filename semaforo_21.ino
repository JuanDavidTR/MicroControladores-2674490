const int pinRojo = 7;
const int pinAmarillo = 6;
const int pinVerde = 5;
const int pinBotonParo = 4;
const int pinBotonMantenimiento = 3;
const int potenciometroPin = A0;

bool mantenimientoActivo = false;
bool amarilloEncendido = false;
int contadorBombilloRojo = 0;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotonParo, INPUT);
  pinMode(pinBotonMantenimiento, INPUT);
  Serial.begin(9600);
}

void Secuencia_1(int delayFactor) {
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);
  delay(5000 / delayFactor);

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinAmarillo, HIGH);
  digitalWrite(pinVerde, LOW);
  delay(1000 / delayFactor);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, HIGH);
  delay(3000 / delayFactor);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, HIGH);
  digitalWrite(pinVerde, LOW);
  delay(1000 / delayFactor);
}

void loop() {
  int delayFactor = map(analogRead(potenciometroPin), 0, 1023, 1, 10); // Mapear el valor analógico del potenciómetro a un factor de retardo
  if (digitalRead(pinBotonMantenimiento) == HIGH) {
    mantenimientoActivo = true;
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarillo, amarilloEncendido ? LOW : HIGH);
    delay(500 / delayFactor);  // Controla la velocidad del titileo del amarillo
    amarilloEncendido = !amarilloEncendido;
  } else {
    mantenimientoActivo = false;
    if (!amarilloEncendido && digitalRead(pinBotonParo) == LOW) {
      Secuencia_1(delayFactor);
      contadorBombilloRojo++; // Incrementa el contador del bombillo rojo
      Serial.print("Bombillo Rojo encendido: ");
      Serial.println(contadorBombilloRojo);
    } else {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinVerde, LOW);
    }
  }
}
