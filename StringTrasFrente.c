#include <stdio.h>

int main(void) {
  char palavra[30], nova[30];
  int i = 0, j = 0;

  printf("Digite uma palavra qualquer: ");
  scanf("%[^\n]", palavra);

  // verifica o tamanho da string
  while (palavra[i] != '\0') {
    i++;
  }

  // faz a leitura de trás pra frente
  for (j = i - 1; j >= 0; j--) {
    // printf("%d\n", j);
    nova[i - j - 1] = palavra[j];
  }

  nova[i] = '\0';

  printf("Palavra de trás para frente: %s", nova);
  return 0;
}