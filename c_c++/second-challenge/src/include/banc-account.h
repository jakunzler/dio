#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

class ContaBancaria {
protected:
    double saldo;

public:
    ContaBancaria(double saldoInicial);
    virtual double getSaldo() const;
    virtual void depositar(double valor);
    virtual void sacar(double valor) = 0; // Método abstrato
};

#endif // CONTA_BANCARIA_H
