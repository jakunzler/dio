#include <iostream>
#include "current-account.h"

ContaCorrente::ContaCorrente(double saldoInicial) : ContaBancaria(saldoInicial) {}

void ContaCorrente::sacar(double valor) {
    if (saldo >= valor) {
        saldo -= valor;
        std::cout << "Saque realizado: " << valor << std::endl;
    } else {
        std::cout << "Saldo insuficiente" << std::endl;
    }
}
