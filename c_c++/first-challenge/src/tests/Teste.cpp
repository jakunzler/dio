#include <cassert>
#include "current-account.h"

void testeSaque() {
    ContaCorrente conta(500);
    conta.sacar(100);
    assert(conta.getSaldo() == 400);

    conta.sacar(600);
    assert(conta.getSaldo() == 400); // Saldo não deve mudar
}

int main() {
    testeSaque();
    std::cout << "Todos os testes passaram!" << std::endl;
    return 0;
}
