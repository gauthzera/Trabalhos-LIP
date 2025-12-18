int tamanhoMaximo = 20;       
int sequencia[50];
int atrasoClique = 30;

const int pinoBuzzer = 2;

// LEDS
const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;
const int ledAzul = 11;

// BOTÕES
const int botaoVermelho = 4;
const int botaoAmarelo = 5;
const int botaoVerde = 6;
const int botaoAzul = 7;

int contador;
int contadorResposta;
int pontuacao = 0;

int tempoLuz = 250;
int tempoEntreLuzes = 350;
int tempoProximaRodada = 1500;

int botaoPressionado;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  pinMode(botaoVermelho, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoAzul, INPUT_PULLUP);

  pinMode(pinoBuzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  delay(500);
  delay(1000);

  int semente = analogRead(A3);
  randomSeed(semente);

  for (int i = 0; i < tamanhoMaximo; i++) {
    sequencia[i] = random(1, 5);
  }

  boolean respostaCerta = true;
  int rodada = 0;

  while (rodada < tamanhoMaximo) {

    contador = 0;
    pontuacao = rodada + 1;

    // Mostrando a sequência
    while (contador <= rodada) {

      botaoPressionado = sequencia[contador];

      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAzul, LOW);

      if (botaoPressionado == 1) {
        digitalWrite(ledVermelho, HIGH);
        tone(pinoBuzzer, 262); // Dó
        delay(tempoEntreLuzes);
        noTone(pinoBuzzer);
        digitalWrite(ledVermelho, LOW);
        delay(50);
      }
      if (botaoPressionado == 2) {
        digitalWrite(ledAmarelo, HIGH);
        tone(pinoBuzzer, 294); // Ré
        delay(tempoEntreLuzes);
        noTone(pinoBuzzer);
        digitalWrite(ledAmarelo, LOW);
        delay(50);
      }
      if (botaoPressionado == 3) {
        digitalWrite(ledVerde, HIGH);
        tone(pinoBuzzer, 330); // Mi
        delay(tempoEntreLuzes);
        noTone(pinoBuzzer);
        digitalWrite(ledVerde, LOW);
        delay(50);
      }
      if (botaoPressionado == 4) {
        digitalWrite(ledAzul, HIGH);
        tone(pinoBuzzer, 349); // Fá
        delay(tempoEntreLuzes);
        noTone(pinoBuzzer);
        digitalWrite(ledAzul, LOW);
        delay(50);
      }

      contador++;
    }

    contadorResposta = 0;

    // Resposta do jogador
    while (contadorResposta <= rodada) {

      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAzul, LOW);

      // botão vermelho (DÓ)
      if (digitalRead(botaoVermelho) == LOW) {
        botaoPressionado = 1;

        tone(pinoBuzzer, 262);
        delay(80);
        noTone(pinoBuzzer);

        if (botaoPressionado == sequencia[contadorResposta]) {
          digitalWrite(ledVermelho, HIGH);
          delay(atrasoClique);
          contadorResposta++;
        } else {
          respostaCerta = false;
          piscarErro();
          contadorResposta = 999;
        }
        while (digitalRead(botaoVermelho) == LOW) { delay(atrasoClique); }
        digitalWrite(ledVermelho, LOW);
      }

      // botão amarelo (RÉ)
      if (digitalRead(botaoAmarelo) == LOW) {
        botaoPressionado = 2;

        tone(pinoBuzzer, 294);
        delay(80);
        noTone(pinoBuzzer);

        if (botaoPressionado == sequencia[contadorResposta]) {
          digitalWrite(ledAmarelo, HIGH);
          delay(atrasoClique);
          contadorResposta++;
        } else {
          respostaCerta = false;
          piscarErro();
          contadorResposta = 999;
        }
        while (digitalRead(botaoAmarelo) == LOW) { delay(atrasoClique); }
        digitalWrite(ledAmarelo, LOW);
      }

      // botão verde (MI)
      if (digitalRead(botaoVerde) == LOW) {
        botaoPressionado = 3;

        tone(pinoBuzzer, 330);
        delay(80);
        noTone(pinoBuzzer);

        if (botaoPressionado == sequencia[contadorResposta]) {
          digitalWrite(ledVerde, HIGH);
          delay(atrasoClique);
          contadorResposta++;
        } else {
          respostaCerta = false;
          piscarErro();
          contadorResposta = 999;
        }
        while (digitalRead(botaoVerde) == LOW) { delay(atrasoClique); }
        digitalWrite(ledVerde, LOW);
      }

      // botão azul (FÁ)
      if (digitalRead(botaoAzul) == LOW) {
        botaoPressionado = 4;

        tone(pinoBuzzer, 349);
        delay(80);
        noTone(pinoBuzzer);

        if (botaoPressionado == sequencia[contadorResposta]) {
          digitalWrite(ledAzul, HIGH);
          delay(atrasoClique);
          contadorResposta++;
        } else {
          respostaCerta = false;
          piscarErro();
          contadorResposta = 999;
        }
        while (digitalRead(botaoAzul) == LOW) { delay(atrasoClique); }
        digitalWrite(ledAzul, LOW);
      }

      if (!respostaCerta) {
        contadorResposta = 999;
        contador = 999;
        rodada = 111;
      }
    }

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);

    delay(tempoProximaRodada);

    rodada++;
  }

  delay(2500);
}

void piscarErro() {
  for (int i = 0; i < 3; i++) {

    tone(pinoBuzzer, 200);  // som de erro
    delay(150);
    noTone(pinoBuzzer);

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(150);

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    delay(150);
  }
}

