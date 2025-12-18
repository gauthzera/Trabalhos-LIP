#include <TimerOne.h>


#include <I2C.h>
#include <II2C.h>
#include <MPU6050.h>
#include <MultiFuncShield.h>

const int VERMELHO = 6;
const int VERDE = 5;
const int AZUL = 0;


void setup() {
  Buzzer ();
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);
}


void Buzzer ()
{
  MFS.beep();                             // Bip curto de 300 milisegundos
  delay(1000);                            // atraso de 1 segundo
                                         // 4 bips curtos , repetidos 3 vezes
  MFS.beep(5, // bip por 50 milisegundos
           5, // silencio por 50 milisegundos
           4, // repete o bip 4 vezes
           3, // repete o loop 3 vezes
           50 // aguarda 500 milisegundos entre os loops
          );
}
//analogRead(A4) FOTORRESISTOR
//digitalRead(9) PRESENÇA digitalRead(0)
//VERMELHO ~6
//VERDE ~5
//AZUL D0


void loop() {
  Serial.println(analogRead(A4));
  //analogWrite(6, 0);
  //analogWrite(5, 0);
  //analogWrite(0, 0); //AZUL


  if(analogRead(A4) > 400){ //sistema ligado se noite
    if(digitalRead(9)){ //se detectar pessoa (no caso sempre detectava por nós estarmos perto do projeto quando gravamos o vídeo)
      MFS.writeLeds(LED_2, OFF);
      MFS.writeLeds(LED_1, ON); //iluminação do poste no modo "forte"
      analogWrite(VERDE, 102);
      analogWrite(VERMELHO, 255);
      analogWrite(AZUL, 153);
    }
    else{
      MFS.writeLeds(LED_1, OFF); //iluminação do poste no modo "fraco"
      MFS.writeLeds(LED_2, ON); //economia de energia
      analogWrite(VERMELHO, 51);
      analogWrite(VERDE, 51);
      analogWrite(AZUL, 255);
    }


  }else{ //sistema desligado se dia
    MFS.writeLeds(LED_1, OFF);
    MFS.writeLeds(LED_2, OFF);
    analogWrite(VERMELHO, 255);
    analogWrite(VERDE, 255);
    analogWrite(AZUL, 255);
  }
  delay(10);
}
