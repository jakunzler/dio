#include <iostream>
#include <string>

#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "banc-account.h"

class ContaCorrente : public ContaBancaria {
public:
    ContaCorrente(double saldoInicial);
    void sacar(double valor) override;
};

#endif // CONTA_CORRENTE_H
