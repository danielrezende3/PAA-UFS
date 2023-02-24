#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int n;
  int* elements;
} t_vector;

t_vector repetidas(t_vector album, t_vector novas) {
  int qnt = 0;
  t_vector reps;
  if (album.n <= novas.n) {
    reps.n = novas.n;
    reps.elements = (int*)malloc((novas.n + 1) * sizeof(int));
  } else {
    reps.n = album.n;
    reps.elements = (int*)malloc((album.n + 1) * sizeof(int));
  }

  for (int i = 0; i < album.n; i++) {
    int left = 0;
    int right = novas.n-1;
    int find = album.elements[i];
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (novas.elements[mid] == find) {
        reps.elements[qnt++] = novas.elements[mid];
        break;
      }
      if (novas.elements[mid] < find) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
    reps.n = qnt;
  return reps;
}

int main() {
  int i, j, k;
  t_vector album, novas, reps;
  scanf("%d", &album.n);
  album.elements = (int*)malloc((album.n + 1) * sizeof(int));
  for (i = 0; i < album.n; i++) {
    scanf("%d", &(album.elements[i]));
  }
  album.elements[i] = INT_MAX;

  scanf("%d", &novas.n);
  novas.elements = (int*)malloc((novas.n + 1) * sizeof(int));
  for (i = 0; i < novas.n; i++) {
    scanf("%d", &(novas.elements[i]));
  }
  novas.elements[i] = INT_MAX;

  reps = repetidas(album, novas);

  for (k = 0; k < reps.n - 1; k++) printf("%d ", reps.elements[k]);
  printf("%d\n", reps.elements[k]);

  free(reps.elements);
  free(album.elements);
  free(novas.elements);

  return 0;
}