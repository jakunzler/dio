/*
  Nome do programa: desafio01.c
  Objetivo do programa: Repetir cada palavra de uma frase informada pelo usuário.
  Autor: Jonas Augusto Kunzler
  Data de criação: 11/07/2024
*/

#include <stdio.h>
#include <string.h>

int main() {
  char mensagem[100];
  
  scanf("%[^\n]", mensagem);
  char* palavra = strtok(mensagem, " ");

  while (palavra != NULL) {
    printf("%s %s ", palavra, palavra);
    
    palavra = strtok(NULL, " ");
  }
  return 0;
}
