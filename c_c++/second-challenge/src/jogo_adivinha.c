#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSecreto, palpite, tentativas = 0;
    char continuar;

    // Inicializa o gerador de números aleatórios
    srand(time(0));
    numeroSecreto = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100

    printf("*********************************\n");
    printf("* Bem-vindo ao jogo de adivinhação! *\n");
    printf("*********************************\n");

    do {
        printf("Digite seu palpite (entre 1 e 100): ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite < numeroSecreto) {
            printf("Seu palpite é menor que o número secreto.\n");
        } else if (palpite > numeroSecreto) {
            printf("Seu palpite é maior que o número secreto.\n");
        } else {
            printf("Parabéns! Você acertou o número secreto em %d tentativas.\n", tentativas);
            printf("Deseja jogar novamente? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar == 's' || continuar == 'S') {
                numeroSecreto = rand() % 100 + 1;
                tentativas = 0;
            } else {
                break;
            }
        }
    } while (1);

    printf("Obrigado por jogar!\n");
    return 0;
}
