// listas circulares
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct no{
	int chave;
	// outros campos;
	struct no *prox;
}TNo;

void insereCircular(TNo **p, int info);
void removeCircular(TNo **p);
void imprime(TNo *p);

int main()
{
	TNo *ultimo=NULL;
	insereCircular(&ultimo, 21);
	insereCircular(&ultimo, 39);
	insereCircular(&ultimo, 82);
	// printf("\n%d", ultimo->chave);
	imprime(ultimo);
	removeCircular(&ultimo);
	printf("\n=======");
	imprime(ultimo);
}

void insereCircular(TNo **p, int info)
{
    assert(p);	
    if(*p == NULL) // if(!(*p)) --> nao tem ninguem na lista
    {	
        *p = (TNo *) malloc(sizeof(TNo));
         if(*p != NULL) // if(*p)
          {	
			(*p)->chave = info;
			(*p)->prox = *p;
          }	
   }
   else // ja tem alguem na lista
   {
   	    TNo *aux = (TNo *) malloc(sizeof(TNo));
        if (aux == NULL) return;
        aux->chave = info;		
        aux->prox = (*p)->prox;	
        (*p)->prox = aux;	// insere no inicio
    // (*p)=(*p)->prox; // *p=aux; --> final
    }
}

void removeCircular(TNo **p)
{
    assert(p);	
    if(*p == NULL) return;	
    TNo *pPrim = (*p)->prox;
    TNo *pPenult = (*p)->prox;
    if(pPrim->prox != pPrim)
    {
       while(pPenult->prox != *p)
       {
			pPenult = pPenult->prox;
       }
	  free(*p);
      *p = pPenult;
       pPenult->prox = pPrim;
     } // if
    else
     {
		free(*p);
		*p = NULL;
     }
}	

void imprime(TNo *p)
{

	if (p==NULL) printf("\nLista Vazia!");
	TNo *aux=p->prox;
	do
	{
		printf("\n%d", aux->chave);
		aux = aux->prox;
	}while(p->prox!=aux); // while(p!=aux);
//	printf("\n%d", p->chave);
}