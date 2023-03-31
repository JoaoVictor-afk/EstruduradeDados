/*
Lista é uma Estrutura de Dados Abstrata com todas as operações: percurso,
pesquisa, inserção ordenada, remoção Lista utiliza struct e ponteiro Há 3 tipos
de listas:
    - simples: um ponteiro (prox) apontando para a próxima célula - a estrutura
básica é igual a da pilha
    - circular: um ponteiro (prox) apontando para a próxima célula, contudo o
último elemento, o seu prox aponta para o primeiro elemento da lista
    - duplas: são dois ponteiros, um prox, apontando para o próximo elemento e
um ant, apontando para o elemento anterior Lista simples possui:
    - a mesma estrutura que pilha
    - percurso: necessidade de p (ponteiro vigente) e pR (ponteiro de
retaguarda, ou seja, que vai atrás do p) for (pR = NULL, p = lista; p ; pR = p,
p = p->prox)
    - inserir ordenado (no início, no fim, ou em qualquer posição do meio)
    - remover deve garantir o encadeamento, pois é escolhido quem remover
*/
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

Celula *localizar(int valor, Celula *lista) {
  Celula *p;
  if (lista) {
    for (p = lista; p; p = p->prox) {
      if (valor == p->conteudo) {
        return p; // achou o valor
      }
    }
  }
  return NULL; // valor não localizado
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

Celula *popularListaAleatoria(Celula *lista, int qtd) {
  srand(time(NULL));
  for (int i = 0; i < qtd; i++) {
    lista = inserir(rand() % 100, lista);
  }
  return lista;
}

Celula *fusao(Celula *lista, Celula *lista2) {
  Celula *Newlista = NULL;
  Celula *p;

  for (p = lista; p; p = p->prox) {
    Newlista = inserir(p->conteudo, Newlista);
  }

  for (p = lista2; p; p = p->prox) {
    Newlista = inserir(p->conteudo, Newlista);
  }

  return Newlista;
}

Celula *fusaoSemRep(Celula *lista, Celula *lista2) {
  Celula *Newlista = NULL;
  Celula *p;

  for (p = lista; p; p = p->prox) {
    if (!localizar(p->conteudo, lista)) {
      Newlista = inserir(p->conteudo, Newlista);
    }
  }

  for (p = lista2; p; p = p->prox) {
    if (!localizar(p->conteudo, lista2)) {
      Newlista = inserir(p->conteudo, Newlista);
    }
  }

  return Newlista;
}

int main() {

  Celula *lista = NULL;
  Celula *lista2 = NULL;

  lista = popularListaAleatoria(lista, 10);
  lista2 = popularListaAleatoria(lista2, 20);

  exibir(lista1);
  exibir(lista2);

  // concatenar a lista1 com a lista2 -> ultimo elemento da lista1 deve apontar
  // para o primeiro elemento da lista2 Celula *lista3 =
  // concatenar(lista1,lista2);

  // mesclar a lista1 com a lista2 -> unificar as duas listas, mantendo a
  // ordenação Celula *lista4 = mesclar(lista1,lista2)

  // mesclar a lista1 com a lista2 -> unificar as duas listas, sem repetir
  // valores Celula *lista5 = mesclarSemRepetidos(lista1,lista2)

  return 1;
}