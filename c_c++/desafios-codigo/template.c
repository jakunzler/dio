/*
  Nome do programa: nome.c
  Objetivo do programa: descrever.
  Autor: Jonas Augusto Kunzler
  Data de criação: XX/XX/XXXX
*/

#include <stdio.h>  /* Biblioteca padrão de entrada e saída */
#include <stdlib.h> /* Biblioteca padrão para alocação de memória, controle de processos, etc. */
#include <string.h> /* Biblioteca para manipulação de strings */

/* Definições de constantes */
#define MAX_BUFFER_SIZE 1024

/* Declaração de funções */
void exemploFuncao(void);

/* Função principal */
int main() {
    /* Declarações de variáveis */
    int variavelExemplo = 0;
    char buffer[MAX_BUFFER_SIZE];

    /* Inicialização */
    memset(buffer, 0, sizeof(buffer));

    /* Implementação da lógica do programa */
    printf("Hello, World!\n");
    exemploFuncao();

    /* Finalização do programa */
    return 0;
}

/*
  Nome da função: exemploFuncao
  Objetivo: Mostrar um exemplo de função.
  Parâmetros: Nenhum
  Retorno: Nenhum
*/
void exemploFuncao() {
    printf("Esta é uma função exemplo.\n");
}
