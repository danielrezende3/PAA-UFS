#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pardepontos {
  int x;
  int y;
} Pardepontos;

float min(float a, float b) { return (a < b) ? a : b; }

float BruteForceClosestPair(Pardepontos *ponto, int tamanho) {
  int i, j, ponto_x, ponto_y;
  float distance, eq;
  distance = FLT_MAX;
  for (i = 0; i < tamanho - 1; i++) {
    for (j = i + 1; j < tamanho; j++) {
      ponto_x = ponto[i].x - ponto[j].x;
      ponto_y = ponto[i].y - ponto[j].y;
      eq = sqrt(pow(ponto_x, 2) + pow(ponto_y, 2));
      distance = min(distance, eq);
    }
  }
  return distance;
}
int main() {
  int count;
  scanf("%d", &count);
  Pardepontos *pontos = (Pardepontos *)malloc(count * sizeof(Pardepontos));
  for (int i = 0; i < count; i++) scanf("%d %d", &pontos[i].x, &pontos[i].y);
  printf("%.4f", BruteForceClosestPair(pontos, count));
  return 0;
}
