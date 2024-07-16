/*
  Nome do programa: desafio02.c
  Objetivo do programa: Receber a quantidade de robôs e as posições de cada robô e retornar o robô que percorreu a maior distância.
  Autor: Jonas Augusto Kunzler
  Data de criação: 16/07/2024
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
    if (N < 1 || N > 10) {
        printf("Número de robôs inválido.\n");
        return 0;
    }

    posicoesDosRobos = (int *) malloc(N * sizeof(int));
    if (posicoesDosRobos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 0;
    }

    for (i = 0; i < N; i++) {
      scanf("%d", &posicoesDosRobos[i]);
    }

    /*
    printf("Posições dos robôs: ");
    for (i = 0; i < N; i++){
      printf("%d; ", posicoesDosRobos[i]);
    }
    printf("\n");
    */

    resultado = maiorDistancia(N, posicoesDosRobos);
    printf("O robô que percorreu a maior distância é o robô %d\n", resultado);

    return 0;
}

/*
  Nome da função: maiorDistancia
  Objetivo: Receber a quantidade de robôs e as posições de cada robô e retornar o robô que percorreu a maior distância.
  Parâmetros: int tamanho - quantidade de robôs, int posicoesDosRobos[] - posições de cada robô.
  Retorno: int - índice do robô que percorreu a maior distância.
*/
int maiorDistancia(int tamanho, int posicoesDosRobos[]) {
    /* int maiorDistancia = 0; */
    int indice = 0;
    int i, j;

    for ( i = 0; i < tamanho; i++) {
        for ( j = i + 1; j < tamanho; j++) {
            if (posicoesDosRobos[i] == posicoesDosRobos[j]) {
                /* maiorDistancia = posicoesDosRobos[i]; */
                indice = i;
            } else if (posicoesDosRobos[i] > posicoesDosRobos[j]) {
                /* maiorDistancia = posicoesDosRobos[i]; */
                indice = i;
            } else {
                /* maiorDistancia = posicoesDosRobos[j]; */
                indice = j;
            }
        }
    }

    /* printf("Maior distância: %d\n", maiorDistancia); */

    return ++indice;
}
