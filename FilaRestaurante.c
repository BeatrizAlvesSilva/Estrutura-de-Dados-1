#include <stdio.h>
#include <stdlib.h>

typedef struct cliente {
  int num_cliente;
  struct cliente *prox;
} TCliente;

typedef struct mesa {
  int num_mesa, cliente;
  struct mesa *prox;
} TMesa;

void inserir_cliente(TCliente **lista);
void inserir_mesa(TMesa **lista, int qtde);
void atendimento(TCliente **clientes, TMesa **mesas);
void imprimir_clientes(TCliente *clientes);
void imprimir_mesas(TMesa *mesas);

int main(void) {
  int op = 0, qtde_mesa;
  TCliente *cliente = NULL;
  TMesa *mesa = NULL;

  printf("Informe a quantidade de mesas em atendimento: ");
  scanf("%d", &qtde_mesa);

  inserir_mesa(&mesa, qtde_mesa);

  while (op != 5) {
    printf("\nESCOLHA UMA OPCAO:\n");
    printf("1 - Inserir cliente\n");
    printf("2 - Atender cliente\n");
    printf("3 - Imprimir fila de clientes\n");
    printf("4 - Historico de atendimento\n");
    printf("5 - Sair\n");
    scanf("%d", &op);
    switch (op) {
    case 1: {
      inserir_cliente(&cliente);
    } break;

    case 2: {
      atendimento(&cliente, &mesa);
    } break;

    case 3: {
      imprimir_clientes(cliente);
    } break;

    case 4: {
		imprimir_mesas(mesa);
    } break;

    case 5: {
      printf("Encerrando programa...\n");
      free(cliente);
      free(mesa);
    } break;
    }
  }
  return 0;
}

// adiciona um novo cliente na fila de espera
// o cliente é adicionado no final da fila, com um número único gerado pelo contador estático aux
void inserir_cliente(TCliente **lista) {
  TCliente *novo = (TCliente *)malloc(sizeof(TCliente));
  static int aux = 0;

  if (!novo) {
    printf("Erro na alocacao de cliente!");
    return;
  } else {
    novo->num_cliente = aux++;
    novo->prox = NULL;
    printf("Cliente %d adicionado com sucesso!\n", novo->num_cliente);
    if (*lista == NULL) {
      *lista = novo;
    } else {
      TCliente *aux = *lista;
      while (aux->prox != NULL) {
        aux = aux->prox;
      }
      aux->prox = novo;
    }
  }
}

void inserir_mesa(TMesa **lista, int qtde) {
  TMesa *novo;
  for (int i = 0; i < qtde; i++) {
    novo = malloc(sizeof(TMesa));
    if (!novo) {
      printf("Erro na alocacao de mesa!");
      return;
    } else {
      novo->num_mesa = i;
      novo->prox = NULL;
		novo->cliente = -1;
      printf("Mesa %d criada com sucesso!\n", i);
      if (*lista == NULL) {
        *lista = novo;
      } else {
        TMesa *aux = *lista;
        while (aux->prox != NULL) {
          aux = aux->prox;
        }
        aux->prox = novo;
      }
    }
  }
}

void atendimento(TCliente **clientes, TMesa **mesas) {
  if (*clientes == NULL) {
    printf("Lista de clientes vazia!\n!");
    return;
  }

  if (*mesas == NULL) {
    printf("Sem mesas disponiveis!\n!");
    return;
  }

  TCliente *cliente_atendido = *clientes;
  *clientes = (*clientes)->prox;

  int mesa = 0;
  printf("Infome o numero da mesa para atendimento: ");
  scanf("%d", &mesa);

  TMesa *mesa_selecionada = *mesas;
  while (mesa_selecionada != NULL && mesa_selecionada->num_mesa != mesa) {
    mesa_selecionada = mesa_selecionada->prox;
  }
  if (mesa_selecionada == NULL) {
    printf("Mesa %d nao encontrada!\n", mesa);
    return;
  } else{
		cliente_atendido->prox = mesa_selecionada->prox;
		mesa_selecionada->prox = cliente_atendido;
	  mesa_selecionada->cliente = cliente_atendido->num_cliente;

		printf("\nCliente %d atendido na mesa %d\n", cliente_atendido->num_cliente,
			   mesa_selecionada->num_mesa);
  }
	cliente_atendido->prox = NULL;
}

void imprimir_clientes(TCliente *clientes) {
  TCliente *aux = clientes;
  printf("Clientes aguardando atendimento:\n");
  while (aux != NULL) {
    printf("Cliente %d\n", aux->num_cliente);
    aux = aux->prox;
  }
}

void imprimir_mesas(TMesa *mesas){
	TMesa *aux = mesas;
	printf("Historico de atendimento: \n");
	while(aux != NULL){
		if(aux->cliente != -1){
			printf("Mesa %d atendeu cliente %d\n", aux->num_mesa, aux->cliente);
		}
		aux = aux->prox;
	}
}