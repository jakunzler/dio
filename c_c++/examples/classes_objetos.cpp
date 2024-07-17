/* Neste exemplo, criamos uma classe chamada "Pessoa", 
que tem dois atributos privados (nome e idade) e dois 
métodos públicos (saudacao e aniversario). O construtor 
da classe recebe os valores iniciais para nome e idade 
e os atribui aos seus respectivos atributos privados.

Em seguida, no método main, criamos dois objetos 
a partir da classe "Pessoa" (pessoa1 e pessoa2) e 
chamamos os métodos "saudacao" e "aniversario" 
de cada um deles para demonstrar seu comportamento. */

#include <iostream>

// Declaração da classe "Pessoa"
class Pessoa {
public:
  // Construtor da classe
  Pessoa(std::string nome, int idade) {
    nome_ = nome;
    idade_ = idade;
  }

  // Métodos da classe
  void saudacao() {
    std::cout << "Olá, meu nome é " << nome_ << " e tenho " << idade_ << " anos." << std::endl;
  }

  void aniversario() {
    idade_++;
    std::cout << "Feliz aniversário! Agora tenho " << idade_ << " anos." << std::endl;
  }

private:
  // Variáveis privadas da classe
  std::string nome_;
  int idade_;
};

int main() {
  // Instanciando objetos a partir da classe "Pessoa"
  Pessoa pessoa1("Alice", 25);
  Pessoa pessoa2("Bob", 30);

  // Chamando métodos dos objetos
  pessoa1.saudacao();
  pessoa2.saudacao();

  pessoa1.aniversario();
  pessoa1.saudacao();

  pessoa2.aniversario();
  pessoa2.saudacao();

  return 0;
}
