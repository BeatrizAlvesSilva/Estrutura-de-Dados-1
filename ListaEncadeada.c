#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int k;
	struct no *prox;
} TNo;

TNo *alocaNo(int k);
void inserirInicio(TNo **p, int k);
void removerInicio(TNo **p);
void imprimir(TNo *p);
void inserirFinal(TNo **p, int k);
TNo *buscarElemento(TNo *p, int valor);

int main(void) {
	TNo *lista = NULL;
	inserirFinal(&lista, 2);
	inserirFinal(&lista, 5);
	inserirFinal(&lista, 8);
	inserirFinal(&lista, 1);
	inserirFinal(&lista, 9);
	imprimir(lista);
	removerInicio(&lista);
	inserirInicio(&lista, 1);
	imprimir(lista);
  return 0;
}

TNo *alocaNo(int k){
	TNo *novo = (TNo *)malloc(sizeof(TNo));
	if(!novo){
		printf("Erro na alocacao.\n");
		return NULL;
	}
	novo->k = k;
	novo->prox = NULL;
	return novo;
}

void inserirInicio(TNo **p, int k){
	TNo *novo = alocaNo(k);
	if(!novo){
		printf("Erro ao inserir.\n");
		return;
	}
	if(*p == NULL){
		*p = novo;
	} else{
		novo->prox = *p;
		*p = novo;
	}
}

void inserirFinal(TNo **p, int k){
	TNo *novo = alocaNo(k);
	if(!novo){
		printf("Erro ao inserir.\n");
		return;
	}
	if(*p == NULL){
		*p = novo;
	} else{
		TNo *aux = *p;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

void removerInicio(TNo **p){
	if(*p == NULL){
		printf("Lista vazia.\n");
		return;
	}
	TNo *aux = *p;
	*p = aux->prox;

	printf("Elemento removido: %d\n", aux->k);
	free(aux);
}

void imprimir(TNo *p){
	while(p){
		printf("[%d]\t", p->k);
		p = p->prox;
	}
}

TNo *buscarElemento(TNo *p, int valor) {
	while (p != NULL) {
		if (p->k == valor) {
			return p;  // retorna o ponteiro para o nó que contém o valor desejado
		}
		p = p->prox;
	}
	return NULL;  // retorna NULL se o valor não for encontrado na lista
}