/*
  Nome do programa: desafio01.c
  Objetivo do programa: Calcular o tempo que um robô de limpeza levará para limpar uma sala.
  Autor: Jonas Augusto Kunzler
  Data de criação: 11/07/2024
*/

#include <stdio.h>
#include <math.h>

int calcula_area(int largura, int comprimento);
int calcula_tempo(int area, int velocidade);

int main() {
  int largura, comprimento, area, tempo;
  int velocidade = 5;

  scanf("%d", &largura);
  scanf("%d", &comprimento);

  area = calcula_area(largura, comprimento);
  tempo = calcula_tempo(area, velocidade);

  if (tempo > 120)
    printf("Tempo de limpeza exede disponibilidade.");
  else
    printf("O robô de limpeza levará %d minutos para limpar a sala.\n", tempo);

  return 0;
}

int calcula_area(largura, comprimento) {
  return largura * comprimento;
}

int calcula_tempo(area, velocidade) {
  int tempo = ceil(area / (float)velocidade);
  return tempo;
}
