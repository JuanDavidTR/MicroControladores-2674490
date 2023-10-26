void setup(){
pinMode(11,INPUT);
pinMode(10,INPUT);
pinMode(9,INPUT);
pinMode(8,INPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
}

void loop()
{
bool A,B,C,D,LED1,LED2,LED3; 
  A=digitalRead(11);
  B=digitalRead(10);
  C=!digitalRead(9);
  D=!digitalRead(8);
  LED2= A&B&C&D;
  digitalWrite(6,LED2);
  LED3= A&&D||C&&D||C&&A||B&&D||B&&A||B&&C;
  digitalWrite(5,LED3);
  LED1= D&&(A&&(B||C)||!A&&!B&&!C||B&&C)||!A&&!D&&(B^C)||A&&B&&C;
  digitalWrite(7,LED1);
}