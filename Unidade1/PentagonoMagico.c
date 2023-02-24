#include <math.h>
#include <stdio.h>

typedef struct Pair {
  int x, y;
} Pair;

int compare(Pair a, Pair b) {
  int flag = 0;
  if (a.x == b.x && a.y == b.y) {
    flag = 1;
  }
  return flag;
}
int main() {
  // definicao de variavel
  int n;
  int size_sol = 0;
  scanf("%d", &n);
  Pair *ponto = (Pair *)malloc(n * sizeof(Pair));
  Pair *solucao = (Pair *)malloc(n * 2 * sizeof(Pair));
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &ponto[i].x, &ponto[i].y);
  }
  // processamento
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int c_maior = 0;
      int c_menor = 0;
      int a = ponto[j].y - ponto[i].y;
      int b = ponto[i].x - ponto[j].x;
      int c = (ponto[i].x * ponto[j].y) - (ponto[i].y * ponto[j].x);
      for (int k = 0; k < n; k++) {
        if (k != i && k != j) {
          int ax = a * ponto[k].x;
          int by = b * ponto[k].y;
          if ((ax + by) > c) {
            c_menor++;
          } else if ((ax + by) < c) {
            c_maior++;
          }
        }
      }
      if (c_maior > 0 && c_menor == 0) {
        solucao[size_sol] = ponto[i];
        solucao[size_sol + 1] = ponto[j];
        size_sol += 2;
      } else if (c_menor > 0 && c_maior == 0) {
        solucao[size_sol] = ponto[i];
        solucao[size_sol + 1] = ponto[j];
        size_sol += 2;
      }
    }
  }
  int is_distinct = 1;
  for (int i = 0; i < size_sol; i += 2) {
    for (int j = i + 1; j < size_sol; j++) {
      if (ponto[i].x == ponto[j].x && ponto[i].y == ponto[j].y) {
        is_distinct = 0;
        break;
      }
      if (!is_distinct) {
        break;
      }
    }
  }
  if (((size_sol + 2 - 1) / 2) == 5) {
    printf("pentagono magico!");
  } else {
    printf("cade a magia?");
  }
  return 0;
}