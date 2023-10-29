const int pinRojo = 7;
const int pinAmarillo = 6;
const int pinVerde = 5;
const int pinBotonParo = 4;
const int pinBotonMantenimiento = 3;

bool mantenimientoActivo = false;
bool amarilloEncendido = false;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBotonParo, INPUT);
  pinMode(pinBotonMantenimiento, INPUT);
}

void Secuencia_1() {
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);
  delay(5000);

  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinAmarillo, HIGH);
  digitalWrite(pinVerde, LOW);
  delay(1000);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, HIGH);
  delay(3000);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, HIGH);
  digitalWrite(pinVerde, LOW);
  delay(1000);
}

void loop() {
  if (digitalRead(pinBotonMantenimiento) == HIGH) {
    mantenimientoActivo = true;
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarillo, amarilloEncendido ? LOW : HIGH);
    delay(500);  // Controla la velocidad del titileo del amarillo
    amarilloEncendido = !amarilloEncendido;
  } else {
    mantenimientoActivo = false;
    if (!amarilloEncendido && digitalRead(pinBotonParo) == LOW) {
      Secuencia_1();
    } else {
      digitalWrite(pinRojo, LOW);
      digitalWrite(pinAmarillo, LOW);
      digitalWrite(pinVerde, LOW);
    }
  }
}
