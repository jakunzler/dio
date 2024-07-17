#include <iostream>
#include <string>

using namespace std;

class Robo {
public:
    int velocidadeAtual = 0;
    int velocidadeMaxima;
    int velocidadeMinima;
    
    Robo(int vmin, int vmax) : velocidadeMinima(vmin), velocidadeMaxima(vmax) {
        velocidadeAtual = vmin;
    }
    
    void acelerar() {
        velocidadeAtual = ++velocidadeAtual;
    }
    
    void desacelerar() {
        velocidadeAtual = --velocidadeAtual;
    }
};

int main() {
    int vmin, vmax;
    string comandos;
    
    cin >> vmin >> vmax;
    cin >> comandos;

    if (vmin < 0 || vmax > 100) {
        cout << "Valores fora do intervalo permitido" << endl;
        return 0;
    }
    
    Robo robo(vmin, vmax);
    for (char comando : comandos) {
        if (comando == 'A') {
            robo.acelerar();
        } else if (comando == 'D') {
            robo.desacelerar();
        }
    }
    cout << robo.velocidadeAtual << endl;
    return 0;
}