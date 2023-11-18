#include <stdio.h>
#include <stdlib.h>

// conferir restrições de linhas e colunas
int restricoesLinhasColunas(int linhas, int colunas) {
  return (linhas < 3 || linhas > 500 || colunas < 3 || colunas > 500 ||
          linhas % 2 == 0);
}

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);

  // verificar restrições de linhas e colunas
  if (restricoesLinhasColunas(N, M)) {
    printf("Restrições não atendidas.\n");
    exit(1);
  }

  char matriz[N][M];

  // Preencher a matriz
  int contar_o = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf(" %c", &matriz[i][j]);

      if (i == 0 && matriz[i][j] == 'o') {
        contar_o++;
      }
    }
    if (contar_o != 1) {
      printf("A primeira linha deve conter exatamente um 'o'.\n");
      exit(1);
    }
  }

  for (int i = 0; i < N; i += 2) {
    if (matriz[i][0] == '#' || matriz[i][M - 1] == '#') {
      printf("As linhas ímpares não podem ter '#' na primeira ou última "
             "coluna.\n");
      exit(1);
    }
  }

  for (int j = 0; j < M; j++) {
    if (matriz[N - 1][j] == '#') {
      printf("A última linha não pode ter '#' em nenhuma coluna.\n");
      exit(1);
    }
  }
  // Vazamento
  for (int i = 0; i < N; i++) {

    // Espalhar para direita
    for (int j = 0; j < M; j++) {
      if (matriz[i][j] == 'o') {
        while (matriz[i][j + 1] == '.' && matriz[i + 1][j] == '#') {
          matriz[i][j + 1] = 'o';
          j++;
        }
      }
    }

    // Espalhar para esquerda
    for (int j = 0; j < M; j++) {
      if (matriz[i][j] == 'o') {
        while (matriz[i][j - 1] == '.' && matriz[i + 1][j] == '#') {
          matriz[i][j - 1] = 'o';
          j--;
        }
      }
    }

    // Espalhar para baixo
    for (int j = 0; j < M; j++) {
      if (matriz[i][j] == 'o' && matriz[i + 1][j] == '.') {
        matriz[i + 1][j] = 'o';
      }
    }
  }

  // Imprimir resultado
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%c", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
