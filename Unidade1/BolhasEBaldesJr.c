#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bubblesort(int arr[], int size) {
  int qnt = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        qnt++;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return qnt;
}
int main() {
  int qnt;
  while (scanf("%d", &qnt) && qnt != 0) {
    int arr[qnt];
    for (int i = 0; i < qnt; i++) {
      scanf("%d", &arr[i]);
    }
    int ans = bubblesort(arr, qnt);
    if ((ans % 2) == 0) {
      printf("Carlos\n");
    } else {
      printf("Marcelo\n");
    }
  }
}