/*
  Nome do programa: desafio02.c
  Objetivo do programa: Calcular a média de veículos por hora.
  Autor: Jonas Augusto Kunzler
  Data de criação: 15/07/2024
*/

#include <stdio.h>  /* Biblioteca padrão de entrada e saída */
#include <math.h>  /* Biblioteca para funções matemáticas */
#include <stdlib.h> /* Biblioteca padrão para alocação de memória, controle de processos, etc. */
#include <string.h> /* Biblioteca para manipulação de strings */

/* Declaração de funções */
int maiorDistancia(int tamanho, int posicoesRobos[]);

/* Função principal */
int main() {
    int i, N, resultado;
    int *posicoesDosRobos;

    scanf("%d", &N);

    posicoesDosRobos = (int *) malloc(N * sizeof(int));
    if (posicoesDosRobos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
      scanf("%d", &posicoesDosRobos[i]);
    }

    resultado = maiorDistancia(N, posicoesDosRobos);
    printf("%d\n", resultado);

    return 0;
}

/*
  Nome da função: maiorDistancia
  Objetivo: 
  Parâmetros: tamanho (int) - tamanho do vetor de veículos, veiculos (int[]) - vetor de veículos por hora.
  Retorno: int - média de veículos por hora.
*/
int maiorDistancia(int tamanho, int posicoesDosRobos[]) {
    int maiorDistancia = 0;
    int indice = 0;
    int i, j, distancia;

    for ( i = 0; i < tamanho; i++) {
        for ( j = i + 1; j < tamanho; j++) {
            distancia = abs(posicoesDosRobos[i] - posicoesDosRobos[j]);
            if (distancia > maiorDistancia) {
                maiorDistancia = distancia;
                indice = i;
            }
        }
    }

    return indice;
}
