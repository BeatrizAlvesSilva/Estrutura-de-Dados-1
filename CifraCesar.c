// cifra de césar = cifra de deslocamento
#include <stdio.h>
#include <string.h>

int main() {
	char palavra[100];
	int i, ascii, cod, chave;

  // grava a string q vai ser codificada
	printf("Informe uma string para ser codificada: ");
	scanf("%[^\n]", palavra);

	// solicita a chave a ser utilizada
	printf("Informe o fator: ");
	scanf("%d", &chave);
	
	for (i = 0; i < strlen(palavra); i++){
		ascii = (int)palavra[i]; // identifica o valor correspondente na tabela ascii
		
		// exceção para as 3 últimas letras do alfabeto
		if ((ascii > 87 && ascii <= 90) || (ascii > 119 && ascii <= 122)){
			cod = (ascii + chave) - 26;
			palavra[i] = (char)cod;
		} else {
				cod = ascii + chave;
				palavra[i] = (char)cod;
			}
	}
	printf("\nString codificada: %s", palavra);
  return 0;
}