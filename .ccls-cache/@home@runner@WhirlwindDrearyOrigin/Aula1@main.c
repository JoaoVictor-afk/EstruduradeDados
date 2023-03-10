#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
  int dado;
  struct no *prox; // ponteiro para o proximo elemento dessa estrutura
} Celula;

Celula *push(int valor, Celula *topo) {
  // alocar memoria
  Celula *novo = (Celula *)malloc(sizeof(Celula));

  // depositar valor
  novo->dado = valor;

  // engatar o novo no ultimo
  novo->prox = topo;

  // retornar o novo top
  return novo;
}

Celula *createList(Celula *pilha) {

  FILE *search;
  char name[200];
  // alocar memoria

  printf("Caminho e nome do arquivo\n");
  scanf("%c", &name);

  while (!feof(search)) {
    fscanf(search, "%d", )
  }

  // engatar o novo no ultimo
  novo->prox = topo;

  // retornar o novo top
  return novo;
}

Celula *remove(Celula *topo) {
  // testar se pilha vazia
  if (!topo) {
    printf("Pilha vazia. Operacao nao realizada\n");
    return topo;
  }

  // ponteiro lixo apontar para o topo/ultimo
  Celula *lixo = topo;

  // topo avanca
  topo = topo->prox;

  // liberar lixo
  free(lixo);

  // retornar novo topo
  return topo;
}

int count(Celula *topo) {
  int qtd = 0;
  Celula *p;
  for (p = topo; p; p = p->prox) {
    qtd++;
  }
  return qtd;
}

void show(Celula *topo) {
  if (!topo) {
    printf("Pilha vazia\n");
  }
  Celula *p;
  for (p = topo; p; p = p->prox) {
    printf("%d\t\n", p->dado);
  }
}

int local(int valor, Celula *topo) {
  Celula *p;
  int qtd = 0;
  if (!topo) {
    printf("Pilha vazia\n");
    return 0;
  }
  for (p = topo; p; p = p->prox) {

    if (valor == p->dado) {
      printf("%d\t\n", p->dado);
      ++qtd;
      if (qtd > 1) {
        remove(p);
        printf("%d\n", qtd);
        return printf("Removeu\n");
      }
    }
  }
  return 0; // passou por toda a pilha e nao encontrou o valor
}
int gePi(Celula *pilharand, int n) {
  srand(time(NULL));
  int i;
  for (i = 0; n >= i; i++) {
    pilharand = psuh(rand() % 100, pilharand);
    return local(10, pilharand);
  }
  return 0;
}

int main() {
  Celula *pilha1 = NULL; // pilha1 é um ponteiro de Celula que vai apontar

  pilha1 = push(12, pilha1);
  pilha1 = push(12, pilha1);
  pilha1 = push(12, pilha1);
  pilha1 = push(25, pilha1);
  pilha1 = push(100, pilha1);

  local(12, pilha1);
  show(pilha1);

  // printf("O numero 12 esta ou nao na pilha? %d", localizado(12, pilha1));

  return 0;
}