/*
  Nome do programa: desafio01.c
  Objetivo do programa: Verificar se um robô está próximo ou longe.
  Autor: Jonas Augusto Kunzler
  Data de criação: 11/07/2024
*/

#include <stdio.h>

char* verificaDistancia(int distancia) {
  if (distancia <= 10) {
    return "O robô está próximo!";
  } else {
    return "O robô está longe!";
  }
}

int main() {
  int distancia;

  /* Ler a entrada com a função "scanf" e atribuir à "distancia". */
  scanf("%d", &distancia);
  
  /* Tendo em vista a função "verificaDistancia", imprima a saída. */
  printf("%s\n", verificaDistancia(distancia));
    
  return 0;
}
