#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// O(n*k)
int main() {
  int tam_l1, tam_l2;
  int i, j, k;
  int total_l;
  scanf("%d%d", &tam_l1, &tam_l2);
  total_l = tam_l1 + tam_l2;
  int l1[tam_l1];
  int l2[tam_l2];
  int *lf = (int *)malloc(total_l * sizeof(int));
  for (i = 0; i < tam_l1; i++) {
    scanf("%d", &l1[i]);
  }
  for (i = 0; i < tam_l2; i++) {
    scanf("%d", &l2[i]);
  }
  i = 0, j = 0, k = 0;
  while (k < total_l && i < tam_l1 && j < tam_l2) {
    if (l1[i] <= l2[j]) {
      lf[k] = l1[i];
      i++;
    } else if (l1[i] > l2[j]) {
      lf[k] = l2[j];
      j++;
    }
    k++;
  }
  while (i == tam_l1 && j < tam_l2) {
    lf[k] = l2[j];
    k++;
    j++;
  }
  while (j == tam_l2 && i < tam_l1)
  {
    lf[k] = l1[i];
    k++;
    i++;
  }
  

  for (i = 0; i < total_l; i++) {
    printf("%d\n", lf[i]);
  }

  return 0;
}

// 1 1 1
// 1 1 1
// 3
// 3
// 1
// 1
// 1
// 1
// 1
// 1