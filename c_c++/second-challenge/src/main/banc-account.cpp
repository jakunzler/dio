#include "banc-account.h"

ContaBancaria::ContaBancaria(double saldoInicial) : saldo(saldoInicial) {}

double ContaBancaria::getSaldo() const {
    return saldo;
}

void ContaBancaria::depositar(double valor) {
    saldo += valor;
}
