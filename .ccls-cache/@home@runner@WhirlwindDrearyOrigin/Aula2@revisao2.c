#include "util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *procurador;
  char nome[200];

  printf("nome do arquivo fonte: ");
  scanf("%s", nome);

  procurador = fopen(nome, "r");

  if (procurador == NULL) {
    printf("arquivo não encontrado");
    return 0;
  }

  int *vetor;
  int contalinha = 0;
  char linha[250];

  do {
    fgets(linha, 250, procurador);
    contalinha++;
  } while (!feof(procurador));

  printf("numero de linhas no documento: %d\n", contalinha);
  vetor = (int *)malloc(sizeof(int) * contalinha);

  fclose(procurador);

  procurador = fopen(nome, "r");

  // poupular o vetor
  int i = 0;

  do {
    fgets(linha, contalinha, procurador);
    vetor[i] = atoi(linha);
    i++;
  } while (!feof(procurador));

  fclose(procurador);

  // calcular
  printf("media: %.2f", media(vetor, contalinha));
  printf("maior: %d", maior(vetor, contalinha));
  printf("menor: %d", menor(vetor, contalinha));

  // exbir
}
