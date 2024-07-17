#include <iostream>
#include <string>

class Produto {
  protected: std::string nome;

  protected: std::string setNome(std::string n) {
    return nome = n;
  }

  private: std::string fornecedor;

  public: Produto(std::string n, std::string f): nome(n), fornecedor(f) {}

  public: std::string getFornecedor() {
    return fornecedor;
  }

  virtual std::string informacoes() = 0;
};

class Eletronico: public Produto {
  int garantia;

  public: Eletronico(std::string n, std::string f, int g): Produto(n, f), garantia(g) {}

  std::string informacoes() override {
    return nome + ", garantia: " + std::to_string(garantia) + " meses";
  }
};

class Vestuario: public Produto {
  std::string tamanho;

  public: Vestuario(std::string n, std::string f, std::string t): Produto(n, f), tamanho(t) {}

  std::string informacoes() override {
    return nome + ", tamanho: " + tamanho;
  }
};

class Pet: public Produto {
  std::string especie;

  public: Pet(std::string n, std::string f, std::string e): Produto(n, f), especie(e) {}

  std::string informacoes() override {
    return nome + ", de " + getFornecedor() + ", especie: " + especie;
  }
};

int main() {
  std::string nome;
  std::string fornecedor;
  char tipo;
  Produto * produto;
  
  std::getline(std::cin, nome);
  std::cin >> tipo;
  
  if (tipo == 'E') {
    int garantia;
    std::cin >> garantia;
    produto = new Eletronico(nome, fornecedor = "padrão", garantia);
  } else if (tipo == 'V') {
    std::string tamanho;
    std::cin >> tamanho;
    produto = new Vestuario(nome, fornecedor = "padrão", tamanho);
  } else if (tipo == 'P') {
    std::string especie;
    std::cin >> fornecedor;
    std::cin >> especie;
    produto = new Pet(nome, fornecedor, especie);
  }
  
  std::cout << produto -> informacoes() << std::endl;
  
  delete produto;
  return 0;
}