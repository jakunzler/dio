/*
  Nome do programa: desafio03.c
  Objetivo do programa: Um modelo de Inteligência Artificial para prever se uma pessoa tem risco de desenvolver diabetes.
  Autor: Jonas Augusto Kunzler
  Data de criação: 16/07/2024
*/

#include <stdio.h>  /* Biblioteca padrão de entrada e saída */
#include <math.h>  /* Biblioteca para funções matemáticas */
#include <stdlib.h> /* Biblioteca padrão para alocação de memória, controle de processos, etc. */
#include <string.h> /* Biblioteca para manipulação de strings */

/* Declaração de funções */
void imprimirDiagnostico(int idade, int concentracaoGlicose, float imc);

/* Função principal */
int main() {
    int idade, concentracaoGlicose;
    float imc;

    scanf("%d", &idade);
    scanf("%d", &concentracaoGlicose);
    scanf("%f", &imc);

    imprimirDiagnostico(idade, concentracaoGlicose, imc);

    return 0;
}

/*
  Nome da função: imprimirDiagnostico
  Objetivo: Receber a idade, a concentração de glicose e o IMC de uma pessoa e imprimir um diagnóstico sobre o risco de diabetes.
  Parâmetros: int idade - idade da pessoa, int concentracaoGlicose - concentração de glicose da pessoa, float imc - IMC da pessoa.
  Retorno: void
*/

void imprimirDiagnostico(int idade, int concentracaoGlicose, float imc) {
    if (concentracaoGlicose < 120 && idade < 40) {
        printf("Você não corre risco de diabetes\n");
    } else if (concentracaoGlicose < 120 && idade >= 40) {
        printf("Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos\n");
    } else if (concentracaoGlicose >= 126) {
        printf("É altamente recomendável que você procure um médico para avaliação\n");
    } else {
        printf("Você tem uma probabilidade de adquirir diabetes. Procure um médico\n");
    }
}