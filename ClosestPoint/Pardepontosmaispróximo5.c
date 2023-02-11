#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Ponto {
  int x;
  int y;
} Ponto;


void ClosestPoint(Ponto *P, int size){}
int main() {
  int size;
  FILE *input;
  FILE *output;
  input = fopen("teste1.txt", "r");
  if (input == NULL) {
    return 1;
  }
  output = fopen("meu_resultado.txt", "w");
  if (output == NULL) {
    return 1;
  }
  fscanf(input, "%d", &size);
  while (size != 0) {
    Ponto P[size];
    for (int i = 0; i < size; i++) fscanf(input, "%d %d", &P[i].x, &P[i].y);
    int n = sizeof(P) / sizeof(P[0]);
    fprintf(output, "%.4f\n", ClosestPoint(P, n));
    fscanf(input, "%d", &size);
  }
  return 0;
}