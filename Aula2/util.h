#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int *vetor, int n) {

  int maior = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (vetor[i] >= maior) {
      maior = vetor[i];
    }
  }
  return maior;
}

int menor(int *vetor, int n) {
  int menor = 0;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (vetor[i] <= menor) {
      menor = vetor[i];
    }
  }
  return menor;
}

float media(int *vetor, int n) {
  float media;
  int i = 0;
  for (i = 0; i < n; i++) {
    media += *vetor;
  }

  return media / n;
}