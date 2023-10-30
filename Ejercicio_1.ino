const int ledInterno = D4;
const int ledAzul = D2;
const int ledRojo = D1;
const int pulsador = D3;

void setup() {
  pinMode(ledInterno, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(pulsador, INPUT);
}

void loop() {
  digitalWrite(ledInterno, HIGH);
  digitalWrite(ledAzul, HIGH);
  delay(500);

  digitalWrite(ledInterno, LOW);
  digitalWrite(ledAzul, LOW);
  delay(500);

  if (digitalRead(pulsador) == LOW) {
    digitalWrite(ledRojo, HIGH);
  } else {
    digitalWrite(ledRojo, LOW);
  }
}
