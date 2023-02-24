#include "util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// menu
// 1 - cadastrar glicemicos
// 2- exibir dados
// 3 sair
// opção

void Cadastrar() {
  FILE *procurador;
  int glicemico;
  char data[10];
  char hora[5];
  procurador = fopen("dados.dat", "a");
  if (procurador == NULL) {
    printf("arquivo não encontrado\n");
    return;
  }
  printf("Valor Glicemico: ");
  scanf("%d", &glicemico);
  printf("Valor data: ");
  scanf("%s", data);
  fflush(stdin);
  printf("Valor Hora: ");
  scanf("%s", hora);

  fprintf(procurador, "%d@%s@%s@", glicemico, data, hora);
  fclose(procurador);
}

void menu() {
  char opcao;

  do {
    printf("1-cadastrar glicemicos\n");
    printf("2-exibir dados\n");
    printf("3-sair\n");
    printf("Opçao:");
    scanf("%c", &opcao);

    switch (opcao) {
    case '1':
      printf("Cadastrar\n");
      Cadastrar();
      break;
    case '2':
      printf("Exibir\n");
      Exibir();
      break;
    case '3':
      printf("Sair");
      return;
    default:
      printf("opção invalidada");
      break;
    }
    fflush(stdin);
  } while (1);
}

int main() { int menu; }