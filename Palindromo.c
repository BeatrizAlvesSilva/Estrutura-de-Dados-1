#include <stdio.h>

int main(void) {

  char string[100], copia[100];
  int i = 0, tam = 0, j = 0, f = 0;

  printf("Digite uma string: ");
  scanf("%[^\n]", &string);

  // verifica o tamanho da string
  while (string[i] != '\0') {
    i++;
  }

  // verifica se é um palíndromo
  for (j = 0; j < i / 2; j++) {
    if (string[j] != string[i - 1 - j]) {
      f = 1;
      break;
    }
  }
  if (f == 1) {
    printf("Não é um palíndromo\n");
  } else {
    printf("É um palíndromo");
  }

  return 0;
}