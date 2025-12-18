/*

AUTORES: 

GABRIEL ULHOA

SAMUEL ELIAS

*/

/* Programa de teste dos Botões do Shield Multi-função

  Blog Eletrogate - https://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino

  Arduino UNO - IDE 1.8.5 - Shield Multi-função para Arduino

  Gustavo Murta   13/junho/2018

  Baseado em http://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/

*/

 

#include <TimerOne.h>         // Biblioteca TimerOne

#include <Wire.h>             // Biblioteca Wire

#include <MultiFuncShield.h>  // Biblioteca Multifunction shield

 

int estadoSistema = 0;

int distance = 0;

const int pinoTrigger = 5;

const int echoPin = 6;

 

long readUltrasonicDistance(int triggerPin, int echoPin) {

  pinMode(triggerPin, OUTPUT);  // Clear the trigger

  digitalWrite(triggerPin, LOW);

  delayMicroseconds(2);

  // Sets the trigger pin to HIGH state for 10 microseconds

  digitalWrite(triggerPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);

  // Reads the echo pin, and returns the sound wave travel time in microseconds

  return pulseIn(echoPin, HIGH);

}




void setup() {

  Serial.begin(9600);          // monitor serial 9600 Bps

  Timer1.initialize();         // inicializa o Timer 1

  MFS.initialize(&Timer1);     // initializa a biblioteca Multi função

  Serial.println("TESTE...");  // imprime mensagem

}

 

int frequencia;

 

void Buzzer(int leituraValida) {

  frequencia = map(leituraValida, 1, 15, 50, 150);

  Serial.println(frequencia);

 

  MFS.beep(5,   // bip por 50 milisegundos

          5,   // silencio por 50 milisegundos

          1,   

          3,   // repete o loop 3 vezes

          frequencia   // aguarda 500 milisegundos entre os loops

  );

}

 

int leituraValida = 0;

 

void loop() {

  distance = 0.01723 * readUltrasonicDistance(pinoTrigger, echoPin);

 

  if (distance < 200) {

    leituraValida = distance;

  }

 

  MFS.write(leituraValida);

  byte btn = MFS.getButton();  // lendo os botões

 

  byte buttonNumber = btn & B00111111;  // comparando os bits das portas analógicas

  byte buttonAction = btn & B11000000;

 

  if (buttonAction == BUTTON_SHORT_RELEASE_IND) {

    estadoSistema = !estadoSistema;

  }

 

  Serial.println(estadoSistema);

 

  if (estadoSistema) {

    if (leituraValida > 50) {

      MFS.writeLeds(LED_1, OFF);

      MFS.writeLeds(LED_2, OFF);

      MFS.writeLeds(LED_3, OFF);

    } else if (leituraValida > 30 && leituraValida <= 50) {

      MFS.writeLeds(LED_1, ON);

      MFS.writeLeds(LED_2, OFF);

      MFS.writeLeds(LED_3, OFF);

    } else if(leituraValida > 15 && leituraValida <= 30){

      MFS.writeLeds(LED_1, ON);

      MFS.writeLeds(LED_2, ON);

      MFS.writeLeds(LED_3, OFF);

    } 

    else if (leituraValida <= 15) {

      MFS.writeLeds(LED_1, ON);

      MFS.writeLeds(LED_2, ON);

      MFS.writeLeds(LED_3, ON);

      Buzzer(leituraValida);

    }

  }

  else {

    MFS.writeLeds(LED_1, OFF);

    MFS.writeLeds(LED_2, OFF);

    MFS.writeLeds(LED_3, OFF);

    MFS.write(0);

  } 

 

  delay(100);

 

}