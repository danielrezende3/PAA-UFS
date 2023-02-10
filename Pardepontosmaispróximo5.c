#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGDISTANCE 10000

typedef struct Pontos {
  int x;
  int y;
} Pontos;
float min(float a, float b) { return (a < b) ? a : b; }
void merge_x(Pontos *B, int tam_B, Pontos *C, int tam_C, Pontos *A, int tam_A) {
  int i, j, k;
  i = 0, j = 0, k = 0;
  while (i < tam_B && j < tam_C) {
    if (B[i].x <= C[j].x) {
      A[k] = B[i];
      i++;
    } else {
      A[k] = C[j];
      j++;
    }
    k++;
  }
  if (i == tam_B)
    for (int q = j; q < tam_C; q++) A[k++] = C[q];
  else {
    for (int q = i; q < tam_B; q++) A[k++] = B[q];
  }
}
void merge_y(Pontos *B, int tam_B, Pontos *C, int tam_C, Pontos *A, int tam_A) {
  int i, j, k;
  i = 0, j = 0, k = 0;
  while (i < tam_B && j < tam_C) {
    if (B[i].y <= C[j].y) {
      A[k] = B[i];
      i++;
    } else {
      A[k] = C[j];
      j++;
    }
    k++;
  }
  if (i == tam_B)
    for (int q = j; q < tam_C; q++) A[k++] = C[q];
  else {
    for (int q = i; q < tam_B; q++) A[k++] = B[q];
  }
}
void mergesort(Pontos *A, int size, int flag) {
  int half_floor, half_ceil;
  float half = (float)size / 2;
  half_floor = floor(half);
  half_ceil = ceil(half);
  Pontos *B = (Pontos *)malloc(half_floor * sizeof(Pontos));
  Pontos *C = (Pontos *)malloc(half_ceil * sizeof(Pontos));
  if (size > 1) {
    for (int i = 0; i < half_floor; i++) {
      B[i].x = A[i].x;
      B[i].y = A[i].y;
    }
    for (int i = 0; i < half_ceil; i++) {
      C[i].x = A[i + half_floor].x;
      C[i].y = A[i + half_floor].y;
    }

    mergesort(B, half_floor, flag);
    mergesort(C, half_ceil, flag);
    if (flag == 0)
      merge_x(B, half_floor, C, half_ceil, A, size);
    else
      merge_y(B, half_floor, C, half_ceil, A, size);
  }
}
float BruteForceClosestPair(Pontos *ponto, int tamanho) {
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
float EfﬁcientClosestPair(Pontos *P, Pontos *Q, int size) {
  int m, half_floor, half_ceil;
  float d, dr, dl, half;
  half = (float)size / 2;
  half_floor = floor(half);
  half_ceil = ceil(half);
  Pontos Pl[half_ceil];
  Pontos Ql[half_ceil];
  Pontos Pr[half_ceil];
  Pontos Qr[half_ceil];
  if (size <= 3)
    return BruteForceClosestPair(P, size);
  else {
    for (int i = 0; i < half_ceil; i++) {
      Pl[i].x = P[i].x;
      Pl[i].y = P[i].y;
      Ql[i].x = Q[i].x;
      Ql[i].y = Q[i].y;
    }
    for (int i = 0; i < half_floor; i++) {
      Pr[i].x = P[i + half_ceil].x;
      Pr[i].y = P[i + half_ceil].y;
      Qr[i].x = Q[i + half_ceil].x;
      Qr[i].y = Q[i + half_ceil].y;
    }
    dl = EfﬁcientClosestPair(Pl, Ql, half_ceil);
    dr = EfﬁcientClosestPair(Pr, Qr, half_floor);
    d = min(dl, dr);
    m = P[half_ceil - 1].x;
    
  }
}

int main() {
  int x, y, casos;
  float result;
  scanf("%d", &casos);

  while (casos != 0) {
    Pontos sorted_x[casos], sorted_y[casos];
    for (int i = 0; i < casos; i++) {
      scanf("%d %d", &x, &y);
      sorted_x[i].x = x;
      sorted_x[i].y = y;
      sorted_y[i].x = x;
      sorted_y[i].y = y;
    }
    mergesort(sorted_x, casos, 0);
    mergesort(sorted_y, casos, 1);
    result = EfﬁcientClosestPair(sorted_x, sorted_y, casos);
    if (result < BIGDISTANCE)
      printf("%.4f\n", result);
    else
      printf("INFINITY", result);
    scanf("%d", &casos);
  }
  return 0;
}