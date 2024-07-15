/*
  Nome do programa: serial_read.ino
  Objetivo do programa: Acender um led de acordo com a letra digitada no monitor serial.
  Autor: Jonas Augusto Kunzler
  Data de criação: 15/07/2024
*/

#define r_led 6 //Definindo a porta
#define g_led 5 //Definindo a porta
#define b_led 4 //Definindo a porta

char option; //criando variável chamada opcao

void setup()
{
  pinMode(r_led, OUTPUT); //definindo a porta como saída
  pinMode(g_led, OUTPUT); //definindo a porta como porta é saída
  pinMode(b_led, OUTPUT); //definindo a porta como porta é saída

  Serial.begin (9600); //Mostrando no monitor o resultado
}

void loop()
{
 option = Serial.read(); //variável recebe a leitura do teclado

  if(option=='R') //Se usuário digitou R
    digitalWrite(r_led, HIGH); //Liga o led vermelho

  if(option=='G')//Se usuário digitou G
    digitalWrite(g_led, HIGH);//Liga o led verde
  
  if(option=='B')//Se usuário ficou R
    digitalWrite(b_led, HIGH);//Liga o led azul
}