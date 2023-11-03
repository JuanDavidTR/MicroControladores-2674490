//Variable donde almacenaremos el valor del potenciometro
long valor;

//Declaramos los pins de los LEDs
int LED_2 = D4;
int LED_3 = D2;
int LED_4 = D1;

void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Inicio de sketch - valores del potenciometro");

  
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
}

void loop() {
  // leemos del pin A0 valor
  valor = analogRead(A0);

  //Imprimimos por el monitor serie
  Serial.print("El valor es = ");
  Serial.println(valor);

  if(valor >= 0 && valor <=255)
  {
       digitalWrite(LED_2, LOW);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, HIGH);
      delay(500);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, LOW);
      delay(500);
      
      
    
  } 
  
  if (valor >= 256 && valor <=511)
  {  
     
      digitalWrite(LED_2, LOW);
      delay(100);
      digitalWrite(LED_2, HIGH);
      delay(100);
  }

  if (valor >= 512 && valor <=767)
  {
    
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, HIGH);
      digitalWrite(LED_4, LOW);
    }

  if (valor >= 768 && valor <=1023)
  {
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_3, LOW);
      digitalWrite(LED_4, HIGH);
   }
}
