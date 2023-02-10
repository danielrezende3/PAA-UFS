#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float min(float a, float b) { return (a < b) ? a : b; }

float EfﬁcientClosestPair(P, Q) {}
// float BruteForceClosestPair(int *x, int *y, int tamanho) {
//   int i, j, ponto_x, ponto_y;
//   float distance, eq;
//   distance = FLT_MAX;
//   for (i = 0; i < tamanho - 1; i++) {
//     for (j = i + 1; j < tamanho; j++) {
//       ponto_x = ponto[i].x - ponto[j].x;
//       ponto_y = ponto[i].y - ponto[j].y;
//       eq = sqrt(pow(ponto_x, 2) + pow(ponto_y, 2));
//       distance = min(distance, eq);
//     }
//   }
//   return distance;
// }
int merge(int B[], int C[], int A[]) {
  int i, j, k;
  int tamanho = sizeof(A) / sizeof(A[0]);
  int p = sizeof(B) / sizeof(B[0]);
  int q = sizeof(C) / sizeof(C[0]);
  i = 0, j = 0, k = 0;
  while (i <) {
    /* code */
  }
}
int mergesort(int A[]) {
  int tamanho = sizeof(A) / sizeof(A[0]);
  int B[tamanho / 2];
  int C[tamanho / 2];
  for (int i = 0; i < tamanho / 2; i++) B[i] = A[i];
  for (int i = tamanho / 2; i < tamanho; i++) C[i] = A[i];
  mergesort(B);
  mergesort(C);
  merge(B, C, A);
}
int main() {
  // int count;
  // float resposta;
  // scanf("%d", &count);
  // int x[count];
  // int y[count];
  // while (count != 0) {
  //   for (int i = 0; i < count; i++) scanf("%d %d", &x[i], &y[i]);
  //   resposta = BruteForceClosestPair(x, y, count);
  //   if (resposta < 10000)
  //     printf("%.4f\n", resposta);
  //   else if (count != 0) {
  //     printf("INFINITY\n");
  //   }
  //   scanf("%d", &count);
  // }

  return 0;
}
