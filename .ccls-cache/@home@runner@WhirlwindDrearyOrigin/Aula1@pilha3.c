#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
programa em linha de comando que recebe um arquivo texto e uma palavra
de busca. o programa, no mínimo, deve retornar se a palavra estah ou
nao no arquivo
*/
void mostraConteudoArquivo(char *nomeArquivo) {
  FILE *procurador;
  procurador = fopen(nomeArquivo, "r");
  if (!procurador)
    return;

  printf("\n#############################\nExibindo o arquivo %s\n",
         nomeArquivo);
  char linha[100];
  do {
    fgets(linha, 100, procurador);
    printf("%s", linha);

  } while (!feof(procurador));

  fclose(procurador);
}

// int localizaPalavraArquivo(char *nomeArquivo, char *palavra) {

//   FILE *procurador;
//   procurador = fopen(nomeArquivo, "r");
//   char linha[100];

//   if (!procurador)
//     return 0;
//   do {
//     fgets(linha, 100, procurador);
//     printf("%s", linha);
//     if (linha == palavra) {
//       return printf("palavra %d localizada no arquivo", palavra);
//     }

//   } while (!feof(procurador));
//   fclose(procurador);
//   return printf("não tem a palavra");
// }

int localizaPalavraArquivo(char *nomeArquivo, char *palavra) {
  FILE *f = fopen(nomeArquivo, "r");
  char c;
  int i;
  char *string_pesquisar = palavra;
  while ((c = fgetc(f)) != EOF) {
    if (c == *string_pesquisar) {

      for (i = 0; i < strlen(string_pesquisar); i++) {

        c = fgetc(f);
        if (c == EOF)
          break;
        if (*(string_pesquisar + i) != c)
          break;
      }

        if(i == strlen(string_pesquisar){
        return printf("palavra %d localizada no arquivo", palavra);

        break; // break para parar de ler o arquivo
        }
    }
  }
  return printf("não tem a palavra");

  fclose(f);
}

int main(int qtdArgumentos, char **vetorArgumentos) {
  if (qtdArgumentos != 3) {
    printf("Problema na quantidade de argumentos.\n");
    exit(0);
  }
  printf("A %s ocorre no arquivo %s %d\n", vetorArgumentos[2],
         vetorArgumentos[1],
         localizaPalavraArquivo(vetorArgumentos[1], vetorArgumentos[2]));
  return 1;
}