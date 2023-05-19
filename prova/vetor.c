
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void metodo2(int *v, int n) {
  if (n > 0) {
    metodo2(v, n - 1);
    printf("\nDigite o valor:");
    scanf("%d", &v[n - 1]);
  }
}

void metodo3(int *v, int n, int original, int destino) {
  if (n > 0) {
    metodo3(v, n - 1, original, destino);
    if (v[n - 1] == original) {
      v[n - 1] = destino;
    }
  }
}

void metodo5(int *v, int n, int ini, int fim) {
  if (n > 0) {

    metodo5(v, n - 1, ini, fim);
    if (v[n - 1] <= ini && v[n - 1] >= fim) {
      printf("[%d]:%d\n", n - 1, v[n - 1]);
    }
  }
}