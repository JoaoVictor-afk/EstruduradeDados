#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
  int conteudo;
  struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *lista) {
  Celula *novo;
  Celula *p, *pR;

  novo = (Celula *)malloc(sizeof(Celula));

  novo->conteudo = valor;
  novo->prox = NULL;

  if (!lista) {
    return novo;
  }

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor < p->conteudo) {
      break;
    }
  }

  if (!pR) {
    novo->prox = p;
    return novo;
  } else if (!p) {
    pR->prox = novo;
  } else {
    pR->prox = novo;
    novo->prox = p;
  }
  return lista;
}

void exibir(Celula *lista) {
  Celula *p;
  if (!lista) {
    printf("Lista vazia.\n");
    return;
  }
  for (p = lista; p; p = p->prox) {
    printf("%d\t", p->conteudo);
  }
  printf("\n");
}

Celula *popular(Celula *lista, int quantidade) {

  int i;

  srand(time(NULL));

  for (i = 0; i < quantidade; i++) {
    lista = inserir(rand() % 100, lista);
  }

  return lista;
}

Celula *popularquivo(Celula *lista) {

  FILE *procurador;
  char nome[200];
  int *vetor;

  printf("nome do arquivo fonte: ");
  scanf("%s", &nome);

  procurador = fopen(nome, "r");
  int i;
  int contalinha = 0;
  char linha[250];
  int media;

  do {
    fgets(linha, contalinha, procurador);
    vetor[i] = atoi(linha);
    media = media + vetor[i];
    lista = inserir(vetor[i], lista);
    i++;
  } while (!feof(procurador));

  printf("%d ", media);
  printf("%d ", media);

  return lista;
}

Celula *excluir(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    return lista;
  }

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->conteudo) {
      printf("Valor localizado e será removido\n");
      break;
    }
  }

  if (!p) {
    printf("Valor não localizado\n");
    return lista;
  }

  if (!pR) {
    lista = lista->prox;
  } else if (!p->prox) {
    pR->prox = NULL;
  } else {
    pR->prox = p->prox;
  }
  free(p);
  return lista;
}

Celula *excluirrepetidos(int valor, Celula *lista) {
  Celula *p, *pR, *backup;

  for (pR = NULL, p = lista; p;) {
    if (valor == p->conteudo) {
      printf("Valor localizado e será removido\n");
      backup = p->prox;
      lista = excluir(valor, p);
      p = backup;

    } else {
      pR = p;
      p = p->prox;
    }
  }

  return lista;
}

Celula *excluirrepetidosDinamico(int valor, Celula *lista) {
  Celula *p, *pR;
  int i = 0;

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->conteudo) {
      i++;
    }
  }
  for (int j = 0; j < i; j++) {
    lista = excluir(valor, lista);
  }
  return lista;
}
Celula *destruirlista(Celula *lista) {
  Celula *pR, *p;

  if (!lista) {
    return lista;
  }

  for (pR = lista, p = lista->prox; p; pR = p, p = p->prox) {
    free(pR);
  }
  free(pR);
}

Celula *unificar(Celula *lista, Celula *lista1) {
  Celula *pR, *p;
  Celula *novo;

  if (!lista) {
    return lista;
  }

  if (!pR) {
    lista = lista->prox;
  } else if (!p->prox) {
    pR->prox = NULL;
  } else {
    pR->prox = p->prox;
  }
}

int main() {
  Celula *lista = NULL;

  lista = popularquivo(lista);

  exibir(lista);

  return 1;
}
