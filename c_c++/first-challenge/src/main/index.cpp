#include <iostream>
#include "current-account.h"

int main() {
    ContaCorrente contaCorrente(500);

    contaCorrente.sacar(100); // Deve permitir o saque
    contaCorrente.sacar(600); // Deve gerar uma mensagem de saldo insuficiente

    return 0;
}
