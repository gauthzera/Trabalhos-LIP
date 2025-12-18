int tempo = 0;  //define variável do tempo que será usada para o código do botão

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(3, INPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  tempo = 0;
  Serial.println(analogRead(A0));
  if (analogRead(A0) <= 90) { //quando estiver de dia
    digitalWrite(11, HIGH);   //verde para os carros
    digitalWrite(10, HIGH);   //vermelho para os pedrestres
    digitalWrite(12, LOW);
    digitalWrite(9, LOW);
    digitalWrite(13, LOW);
    while (digitalRead(3) != 1 && tempo < 18) { //código do botão
      delay(1000);
      tempo += 1;
    }
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH); //luz amarela
    digitalWrite(10, HIGH); //vermelho pra o pedreste
    digitalWrite(13, LOW);
    digitalWrite(9, LOW);
    delay(3000); //espera por 3 segundos
    digitalWrite(13, HIGH);     //vermelho pra o carro
    digitalWrite(9, HIGH);  //verde para o pedestre
    tone(6, 523, 1000); // toca o som por 1 segundo
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    delay(8000); // espera por 8 segundo
  }
  if (analogRead(A0) >= 90) { //quando estiver a noite
    digitalWrite(12, HIGH);
    delay(1000);      //a luz amarela alterna entre ligado e desligado
    digitalWrite(12, LOW);
    delay(1000);
}
}