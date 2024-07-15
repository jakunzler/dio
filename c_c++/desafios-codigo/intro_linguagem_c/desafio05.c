/*
  Nome do programa: desafio01.c
  Objetivo do programa: Classificar números positivos e negativos.
  Autor: Jonas Augusto Kunzler
  Data de criação: 11/07/2024
*/

#include <stdio.h>

void classificarNumero(int numero, int *positivos, int *negativos) {
  if (numero < 0) {
    printf("negativo!\n");
    (*negativos)++;
  } else if (numero > 0) {
    printf("positivo!\n");
    (*positivos)++;
  }
}

int main() {
  int numero, positivos = 0, negativos = 0;
  
  while (1) {
    scanf("%d", &numero);
    if (numero == 0) {
      break;
    }
    classificarNumero(numero, &positivos, &negativos);
  }
  
  printf("%d números positivos, %d números negativos\n", positivos, negativos);
  
  return 0;
}
