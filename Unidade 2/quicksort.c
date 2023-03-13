#include <stdio.h>

void swap(int *A, int *B) {
  int tmp;
  tmp = *A;
  *A = *B;
  *B = tmp;
}
int hoare_partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low - 1;
  int j = high + 1;
  while (1) {
    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j) {
      return j;
    }

    swap(&arr[i], &arr[j]);
  }
}
void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pivot_index = hoare_partition(arr, low, high);
    quicksort(arr, low, pivot_index);
    quicksort(arr, pivot_index + 1, high);
  }
}
int main() {
  int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, size-1);
  return 0;
}