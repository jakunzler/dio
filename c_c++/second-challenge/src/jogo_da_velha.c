#include <stdio.h>

#define N 3

void inicializaTabuleiro(char tabuleiro[N][N]);
void exibeTabuleiro(char tabuleiro[N][N]);
int verificaVitoria(char tabuleiro[N][N]);
int checaEmpate(char tabuleiro[N][N]);
void fazJogada(char tabuleiro[N][N], char jogador);

int main() {
    char tabuleiro[N][N];
    char jogadorAtual = 'X';
    int vitoria = 0;

    inicializaTabuleiro(tabuleiro);

    while (1) {
        exibeTabuleiro(tabuleiro);
        fazJogada(tabuleiro, jogadorAtual);
        
        if (verificaVitoria(tabuleiro)) {
            exibeTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }
        
        if (checaEmpate(tabuleiro)) {
            exibeTabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }
        
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}

void inicializaTabuleiro(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibeTabuleiro(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < N - 1) printf("|");
        }
        printf("\n");
        if (i < N - 1) printf("---|---|---\n");
    }
}

int verificaVitoria(char tabuleiro[N][N]) {
    // Verifica linhas
    for (int i = 0; i < N; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
    }
    
    // Verifica colunas
    for (int j = 0; j < N; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ')
            return 1;
    }
    
    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;
    
    return 0;
}

int checaEmpate(char tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void fazJogada(char tabuleiro[N][N], char jogador) {
    int linha, coluna;

    while (1) {
        printf("Jogador %c, entre com sua jogada (linha e coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha-1][coluna-1] == ' ') {
            tabuleiro[linha-1][coluna-1] = jogador;
            break;
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
}
