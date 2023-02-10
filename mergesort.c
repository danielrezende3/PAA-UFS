#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int *B, int tam_B, int *C, int tam_C, int *A, int tam_A) {
  int i, j, k;
  i = 0, j = 0, k = 0;
  while (i < tam_B && j < tam_C) {
    if (B[i] <= C[j]) {
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
void mergesort(int *A, int size) {
  int half_B, half_C;
  float half = (float)size / 2;
  half_B = floor(half);
  half_C = ceil(half);
  int *B;
  int *C;
  B = (int *)malloc(half_B * sizeof(int));
  C = (int *)malloc(half_C * sizeof(int));
  if (size > 1) {
    for (int i = 0; i < half_B; i++) {
      B[i] = A[i];
    }
    for (int i = 0; i < half_C; i++) {
      C[i] = A[half_B + i];
    }

    mergesort(B, half_B);
    mergesort(C, half_C);
    merge(B, half_B, C, half_C, A, size);
  }
}

int main() {
  int Arr[] = {2,3,4,2,3,4};
  int size = sizeof(Arr) / sizeof(Arr[0]);
  mergesort(Arr, size);
}