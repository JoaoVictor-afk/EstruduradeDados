#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAML 4
#define TAMC 4

void metodo1(int matriz[TAML][TAMC], int lin, int col, int backLin,
             int backcol) {
  if (col > 0) {
    metodo1(matriz, lin, col - 1, backLin, backcol);
    if (col == lin) {
      printf("%d\t", matriz[lin - 1][col - 1]);
    }
  } else if (lin - 1 > 0) {
    metodo1(matriz, lin - 1, backcol, backLin, backcol);
    printf("\n");
  }
}

void metodo4(int matriz[TAML][TAMC], int lin, int col, int backLin, int backcol,
             int linhaExib) {
  if (col > 0) {
    metodo4(matriz, lin, col - 1, backLin, backcol, linhaExib);
    if (linhaExib == lin) {
      printf("%d\t", matriz[lin - 1][col - 1]);
    }
  } else if (lin - 1 > 0) {
    metodo4(matriz, lin - 1, backcol, backLin, backcol, linhaExib);
    printf("\n");
  }
}
