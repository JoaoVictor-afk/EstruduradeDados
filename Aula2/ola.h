
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int matricula;
  char nome[100];
  struct no *prox;
} Cliente;

void *popular(int n, Cliente vetor[]) {
  srand(time(NULL));
  // alocar memoria
  for (int i = 0; i < n; i++) {
    printf("Nome: ");
    scanf("%s", vetor[i].nome);
    vetor[i].matricula = 100 + rand() % 100;
  }
}

void exibir(int n, Cliente vetor[]) {
  if (!vetor) {
    printf("Pilha vazia\n");
  }
  for (int i = 0; i < n; i++) {
    printf("Nome: %d", vetor[i].nome);
    printf("Nome: %d", vetor[i].matricula);
  }
}