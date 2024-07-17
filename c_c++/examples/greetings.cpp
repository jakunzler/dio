// Explicação do Código:

// Classe Pessoa:

// A classe Pessoa tem atributos privados: nome, diaNascimento, mesNascimento e anoNascimento.
// Um método privado calcularIdade calcula a idade atual da pessoa.
// O construtor Pessoa inicializa os atributos com os valores fornecidos.

// Métodos Públicos:

// saudacao: Imprime uma mensagem de saudação que inclui o nome e a idade calculada da pessoa.
// aniversario: Imprime a data de nascimento da pessoa.
// Função main: Cria duas instâncias da classe Pessoa e chama os métodos saudacao e aniversario para cada instância.

#include <iostream>
#include <string>
#include <ctime>

class Pessoa {
private:
    std::string nome;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;

    int calcularIdade() {
        time_t t = time(0);
        tm* now = localtime(&t);
        int anoAtual = now->tm_year + 1900;
        int mesAtual = now->tm_mon + 1;
        int diaAtual = now->tm_mday;

        int idade = anoAtual - anoNascimento;

        if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
            idade--;
        }

        return idade;
    }

public:
    // Construtor
    Pessoa(std::string nome, int diaNascimento, int mesNascimento, int anoNascimento) 
        : nome(nome), diaNascimento(diaNascimento), mesNascimento(mesNascimento), anoNascimento(anoNascimento) {}

    // Método de saudação
    void saudacao() {
        std::cout << "Olá, meu nome é " << nome << " e eu tenho " << calcularIdade() << " anos." << std::endl;
    }

    // Método para informar a data de aniversário
    void aniversario() {
        std::cout << "Meu aniversário é em " << diaNascimento << "/" << mesNascimento << "/" << anoNascimento << "." << std::endl;
    }
};

int main() {
    Pessoa pessoa1("João", 15, 7, 1990);
    pessoa1.saudacao();
    pessoa1.aniversario();

    Pessoa pessoa2("Maria", 25, 12, 1985);
    pessoa2.saudacao();
    pessoa2.aniversario();

    return 0;
}
