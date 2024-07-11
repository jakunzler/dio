#include <stdio.h>
#include <string.h>

int main() {
  char mensagem[100];
  
  scanf("%[^\n]", mensagem);
  char* palavra = strtok(mensagem, " ");

  while (palavra != NULL) {
    printf("%s %s ", palavra, palavra);
    
    palavra = strtok(NULL, " ");
  }
  return 0;
}
