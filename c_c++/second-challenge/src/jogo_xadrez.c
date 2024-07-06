#include <stdio.h>
#include <stdlib.h>

#define N 8

void inicializaTabuleiro(char tabuleiro[N][N]);
void exibeTabuleiro(char tabuleiro[N][N]);
void moverPeca(char tabuleiro[N][N], int origemX, int origemY, int destinoX, int destinoY);

int main() {
    char tabuleiro[N][N];
    inicializaTabuleiro(tabuleiro);
    exibeTabuleiro(tabuleiro);

    // Exemplo de movimentação de uma peça (altere conforme necessário)
    moverPeca(tabuleiro, 1, 0, 2, 0); // Mover peão de (1, 0) para (2, 0)
    exibeTabuleiro(tabuleiro);

    return 0;
}

void inicializaTabuleiro(char tabuleiro[N][N]) {
    // Inicializa as peças pretas
    char pecasPretas[8] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    char pecasBrancas[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < N; i++) {
        tabuleiro[0][i] = pecasPretas[i];
        tabuleiro[1][i] = 'p';
        tabuleiro[6][i] = 'P';
        tabuleiro[7][i] = pecasBrancas[i];
    }
    // Inicializa os espaços vazios
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibeTabuleiro(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void moverPeca(char tabuleiro[N][N], int origemX, int origemY, int destinoX, int destinoY) {
    if (tabuleiro[origemX][origemY] != ' ' && tabuleiro[destinoX][destinoY] == ' ') {
        tabuleiro[destinoX][destinoY] = tabuleiro[origemX][origemY];
        tabuleiro[origemX][origemY] = ' ';
    } else {
        printf("Movimento inválido!\n");
    }
}
