#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pontos {
  int x;
  int y;
} Pontos;

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

int main() {
  Pontos P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  int size = sizeof(P) / sizeof(P[0]);
  // flag 0 means x, flag 1 means y
  mergesort(P, size, 0);
  return 0;
}