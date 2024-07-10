#include <stdio.h>

/* Funções para operações aritméticas básicas */
float adicionar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

/* Funções para interação com o usuário */
void orienta();
int menu();
float calcula();
void finaliza();

int main() {
    /* char ch; */
    int program_counter = 1, item_menu;
    float resultado;

    orienta();

    while (program_counter > 0) {

        item_menu = menu();

        switch(item_menu) {
            case 1:
                orienta();
                break;
            case 2:
                resultado = calcula();
                printf("Resultado da operacao: %.2f\n", resultado);
                break;
            case 3:
                finaliza();
                return 0;
            case 4:
                printf("Opcao 4\n");
                break;
            default:
                printf("Opcao invalida\n");
                return 1;
        }
        
        /* printf("\n"); */
        /* printf("Pressione a tecla q para encerrar ou outra tecla qualquer para continuar.\n"); */
        /* scanf("%s", &ch); */
        /* printf("Tecla digitada: %d\n", ch); */
        /* if (ch == 113) { Enter key */
        /*     return 0; */
        /* } */

        program_counter++;
    }

    return 0;
}

float adicionar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: Divisao por zero\n");
        return 0;
    }
}

void orienta() {
    printf("\n\n");
    printf("Bem vindo a a calculadora desenvolvida em linguagem C!\n");
    printf("Este programa e uma calculadora simples que realiza as 4 operacoes aritmeticas basicas.\n");
    printf("Para utiliza-lo, insira dois operandos e selecione a operacao desejada.\n");
    printf("O resultado da operacao sera exibido na tela.\n");
}

int menu() {
    int opcao;

    printf("\n");
    printf("Selecione a operacao desejada:\n");
    printf("1 - orientar o usuario\n");
    printf("2 - realizar a operacao\n");
    printf("3 - finalizar o programa\n");
    printf("4 - teste\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

float calcula() {
    float num1, num2, resultado;
    char operador;
    
    printf("\n");
    printf("Insira o primeiro operando: ");
    scanf("%f", &num1);
    printf("Insira o segundo operando: ");
    scanf("%f", &num2);

    /* Menu para selecionar a operação */
    printf("\n");
    printf("Selecione a operacao desejada:\n");
    printf("+: Adicao\n");
    printf("-: Subtracao\n");
    printf("*: Multiplicacao\n");
    printf("/: Divisao\n");
    printf("Operador: ");
    scanf(" %c", &operador);
    printf("\n");

    /* Realiza a operação selecionada */

    switch(operador) {
        case '+':
            resultado = adicionar(num1, num2);
            break;
        case '-':
            resultado = subtrair(num1, num2);
            break;
        case '*':
            resultado = multiplicar(num1, num2);
            break;
        case '/':
            resultado = dividir(num1, num2);
            break;
        default:
            printf("Operador invalido\n");
            return 1;
    }

    return resultado;

}

void finaliza() {
    printf("Obrigado por utilizar a calculadora!\n");
    printf("Ate a proxima!\n");
}