#include <stdio.h>
#include <stdlib.h>

/* Funções para operações aritméticas básicas e de programador */
float adicionar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
int binario_para_decimal(int bin);
int decimal_para_binario(int dec);

int main() {
    float num1, num2, resultado;
    int escolha, num;
    char operador;

    printf("Escolha o tipo de calculadora:\n");
    printf("1. Aritmética\n");
    printf("2. Programador\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("Digite a operação (ex: 2 + 3): ");
        scanf("%f %c %f", &num1, &operador, &num2);

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
                printf("Operador inválido\n");
                return 1;
        }

        printf("Resultado: %.2f\n", resultado);
    } else if (escolha == 2) {
        printf("Escolha a operação:\n");
        printf("1. Binário para Decimal\n");
        printf("2. Decimal para Binário\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("Digite o número binário: ");
            scanf("%d", &num);
            resultado = binario_para_decimal(num);
            printf("Decimal: %d\n", (int)resultado);
        } else if (escolha == 2) {
            printf("Digite o número decimal: ");
            scanf("%d", &num);
            resultado = decimal_para_binario(num);
            printf("Binário: %d\n", (int)resultado);
        } else {
            printf("Opção inválida\n");
        }
    } else {
        printf("Opção inválida\n");
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
        printf("Erro: Divisão por zero\n");
        return 0;
    }
}

int binario_para_decimal(int bin) {
    int decimal = 0, base = 1, rem;
    while (bin > 0) {
        rem = bin % 10;
        decimal = decimal + rem * base;
        bin = bin / 10;
        base = base * 2;
    }
    return decimal;
}

int decimal_para_binario(int dec) {
    int bin = 0, base = 1, rem;
    while (dec > 0) {
        rem = dec % 2;
        bin = bin + rem * base;
        dec = dec / 2;
        base = base * 10;
    }
    return bin;
}
