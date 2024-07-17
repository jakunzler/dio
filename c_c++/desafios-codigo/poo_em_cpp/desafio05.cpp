#include <iostream>
#include <string>

using namespace std;

enum Naipe {
    Paus = 0, Ouros = 1, Copas = 2, Espadas = 3
};

enum Valor {
    As = 1, Valete = 2, Dama = 3, Rei = 4
};

class Carta {
private:
    Naipe naipe;
    Valor valor;

public:
    Carta(Naipe n, Valor v) {
        naipe = n;
        valor = v;
    }

    Naipe getNaipe() {
        return naipe;
    }

    Valor getValor() {
        return valor;
    }

    string getNaipeAsString() {
        switch (naipe) {
            case Paus: return "Paus";
            case Ouros: return "Ouros";
            case Copas: return "Copas";
            case Espadas: return "Espadas";
            default: return "";
        }
    }

    string getValorAsString() {
        switch (valor) {
            case As: return "Ás";
            case Valete: return "Valete";
            case Dama: return "Dama";
            case Rei: return "Rei";
            default: return "";
        }
    }
};

int main() {
    int valorEscolhido, naipeEscolhido;

    cin >> valorEscolhido;
    cin >> naipeEscolhido;

    Carta cartaEscolhida(static_cast<Naipe>(naipeEscolhido), static_cast<Valor>(valorEscolhido));

    cout << "Carta escolhida: " << cartaEscolhida.getValorAsString() << " de " << cartaEscolhida.getNaipeAsString() << endl;

    return 0;
}
