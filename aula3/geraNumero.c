#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int qtdargumento, char **vetorArgumentos) {

  int qtdNumeros = atoi(vetorArgumentos[1]);
  int faixa = atoi(vetorArgumentos[2]);
  char nome[200];
  strcpy(nome, vetorArgumentos[3]);

  if (qtdargumento != 4 || qtdNumeros == 0 || faixa == 0) {
    printf("problemas com parametros");
    return 0;
  }
  FILE *procurador;
  srand(time(NULL));
  procurador = fopen(nome, "w");
  for (int i = 1; i < qtdNumeros; i++) {
    fprintf(procurador, "%d\n", rand() % faixa);

    fflush(procurador);
  }

  fclose(procurador);

  return 1;
}