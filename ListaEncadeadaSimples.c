#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int k; 
	struct no *prox; // aponta para o próximo nó da lista
} TNo;

TNo *alocarNo(int k);
void inserirNo(TNo **no, int k);
void imprimir(TNo *l);

int main(void) {
  TNo *no = NULL;
	inserirNo(&no, 3);
	inserirNo(&no, 19);
	inserirNo(&no, 91);
	inserirNo(&no, 15);
	inserirNo(&no, 63);
	inserirNo(&no, 12);
	inserirNo(&no, 33);
	inserirNo(&no, 65);
	inserirNo(&no, 10);
	inserirNo(&no, 21);

	imprimir(no);
	
  return 0;
}

// função que aloca dinamicamente memória pra um novo nó usando malloc
// se a alocação falhar exibe uma mensagem de erro
// caso contrário o valor k é atribuído ao campo k do nó e o ponteiro prox é inicializado como NULL, indicando que ainda não há próximo nó
// a função retorna um ponteiro para o novo nó criado
TNo *alocarNo(int k){
	TNo *novo = (TNo*)malloc(sizeof(TNo));
	if(!novo){
		printf("Erro na alocacao.\n");
		return NULL;
	} else{
		novo->k = k;
		novo->prox = NULL;
		return novo;
	}
}

// o novo nó é criado usando a função alocarNo
// se a lista estiver vazia então o novo nó se torna o primeiro da lista
// se a lista não estiver vazia o código percorre a lista até encontrar o último nó (onde prox é NULL) e coloca o novo nó como o próximo desse nó
void inserirNo(TNo **no, int k){
	TNo *novo = alocarNo(k);
	if(!novo){
		printf("Erro na alocacao.\n");
		return;
	} else{
		if(*no == NULL){
			*no = novo;
		} else{
			TNo *aux = *no;
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		
	}
}


// imprime todos os nós da lista - recursividade
void imprimir(TNo *l){
	if(l != NULL){
		imprimir(l->prox);
		printf("[%d]\t", l->k);
	}
}