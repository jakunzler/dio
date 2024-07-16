/*
  Nome do programa: desafio04.c
  Objetivo do programa: Receber informações de livros e identificar o livro mais antigo.
  Autor: Jonas Augusto Kunzler
  Data de criação: 16/07/2024
*/

#include <stdio.h>
#include <stdlib.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int ano;
};

int main() {
    int n;
    scanf("%d", &n);
    
    struct Livro biblioteca[n];
    
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", biblioteca[i].titulo);
        scanf(" %[^\n]", biblioteca[i].autor);
        scanf("%d", &biblioteca[i].ano);
    }
    
    int indiceLivroMaisAntigo = 0;
    
    for (int i = 1; i < n; i++) {
        if (biblioteca[i].ano < biblioteca[indiceLivroMaisAntigo].ano) {
            indiceLivroMaisAntigo = i;
        }
    }
    
    printf("%s\n", biblioteca[indiceLivroMaisAntigo].titulo);
    printf("%s\n", biblioteca[indiceLivroMaisAntigo].autor);
    printf("%d\n", biblioteca[indiceLivroMaisAntigo].ano);
    
    return 0;
}
