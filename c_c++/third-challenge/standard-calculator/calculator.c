#include <stdio.h>

// Funções para operações aritméticas básicas
float adicionar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);

int main() {
    float num1, num2, resultado;
    char operador;

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
