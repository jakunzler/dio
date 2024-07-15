/*
  Nome do programa: desafio02.c
  Objetivo do programa: Classificar um animal de acordo com suas características.
  Autor: Jonas Augusto Kunzler
  Data de criação: 11/07/2024
*/

#include <stdio.h>

int main() {
  float peso, altura;
  char temPelos, ehMamifero;

  scanf("%f", &peso);
  scanf("%f", &altura);
  scanf(" %c", &temPelos);
  scanf(" %c", &ehMamifero);
  
  if (peso >= 2000 && altura >= 300) {
    printf("O animal é um elefante!");
  } else if (temPelos == 's' && ehMamifero == 's' && altura == 150) {
    printf("O animal é um cavalo!");
  } else if (ehMamifero == 's' && temPelos == 's' && altura <= 100) {
    printf("O animal é um cachorro!");
  } else if (temPelos == 'n' && ehMamifero == 'n') {
    printf("O animal é uma serpente!");
  } else if (temPelos == 'n' && ehMamifero == 's') {
    printf("O animal é uma tartaruga!");
  } else {
    printf("Não foi possível classificar o animal!");
  }

  return 0;
}