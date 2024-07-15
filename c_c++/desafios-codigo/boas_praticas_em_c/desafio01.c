/*
  Nome do programa: desafio01.c
  Objetivo do programa: Calcular a média de veículos por hora.
  Autor: Jonas Augusto Kunzler
  Data de criação: 15/07/2024
*/

#include <stdio.h>  /* Biblioteca padrão de entrada e saída */
#include <math.h>  /* Biblioteca para funções matemáticas */
#include <stdlib.h> /* Biblioteca padrão para alocação de memória, controle de processos, etc. */
#include <string.h> /* Biblioteca para manipulação de strings */

/* Declaração de funções */
int mediaVeiculosHora(int tamanho, int veiculos[]);
int round(double x);  /* Declaração da função de arredondamento */

/* Função principal */
int main() {
    int tamanho, i;
    int *veiculos;

    scanf("%d", &tamanho);

    veiculos = (int *) malloc(tamanho * sizeof(int));
    if (veiculos == NULL) {
      printf("Erro de alocação de memória.\n");
      return 1;
    }

    for (i = 0; i < tamanho; i++) {
      scanf("%d", &veiculos[i]);
    }

    printf("Média de veículos por hora: %d\n", mediaVeiculosHora(tamanho, veiculos));

    free(veiculos);

    return 0;
}

/*
  Nome da função: mediaVeiculosHora
  Objetivo: Calcular a média de veículos por hora.
  Parâmetros: tamanho (int) - tamanho do vetor de veículos, veiculos (int[]) - vetor de veículos por hora.
  Retorno: int - média de veículos por hora.
*/
int mediaVeiculosHora(int tamanho, int veiculos[]) {
  int i, soma = 0;

  for (i = 0; i < tamanho; i++) {
    soma += veiculos[i];
  }
  
  return round((double)soma / tamanho);
}

/*
  Nome da função: round
  Objetivo: Arredondar um valor para o inteiro mais próximo.
  Parâmetros: x (double) - valor a ser arredondado.
  Retorno: int - valor arredondado.
*/
int round(double x) {
    return (int)(x + 0.5);
}