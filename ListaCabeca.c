#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox;
} TNo;

typedef struct cabeca{
	TNo *prim, *ult;
} TCabeca;

TCabeca *criaCabeca(){
	TCabeca *novo = NULL;
	novo = (TCabeca *)malloc(sizeof(TCabeca));
	if(novo){
		novo->prim = NULL;
		novo->ult = NULL;
		return novo;
	}
}

// enfileirar
void insereFila(TCabeca *p, int k){
	// insere no final
	TNo *novo = NULL;
	novo = (TNo *)malloc(sizeof(TNo));
	if(novo){
		novo->chave = k;
		novo->prox = NULL;
		if(p->ult != NULL){
			p->ult->prox = novo;
		}
		p->ult = novo;
		// se a lista estiver vazia
		if(p->prim == NULL){
			p->prim = novo;
		}
	}
}

// desenfileirar
void removeFila(TCabeca *p){
	if(p->prim){
		TNo *aux = p->prim;
		p->prim = p->prim->prox;
		free(aux);
		if(p->prim == NULL){
			p->ult = NULL;
		}
	} else{
		printf("Lista vazia!");
	}
}

void imprime(TNo *p){
	if(p == NULL){
		printf("\nLista Vazia!");
		return;
	}
	while(p){
		printf("%d\t", p->chave);
		p=p->prox;
	}
}

int main(void) {
	TCabeca *fila = criaCabeca();
	insereFila(fila, 4);
	insereFila(fila, 9);
	insereFila(fila, 1);
	insereFila(fila, 3);
	insereFila(fila, 7);
	imprime(fila->prim);
	removeFila(fila);
	printf("\n*---------------*\n");
	imprime(fila->prim);
	insereFila(fila, 5);
	printf("\n*---------------*\n");
	imprime(fila->prim);
  	return 0;
}