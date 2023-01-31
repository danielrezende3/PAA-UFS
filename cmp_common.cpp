#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
int main() {
  int i = 0;
  int j = 0;
  int k = 0;
  int interations = 0;
  int list_A[] = {3, 5, 7};
  int list_B[] = {2, 4, 6};
  int size_list_A = sizeof(list_A) / sizeof(int);
  int size_list_B = sizeof(list_B) / sizeof(int);
  int smaller_list = min(size_list_A, size_list_B);
  int combined[size_list_A + size_list_B] = {};

  while (size_list_A != i && size_list_B != j) {
    if (list_A[i] == list_B[j]) {
      combined[k] = list_A[i];
      k++;
      i++;
      j++;
      interations++;
    } else {
      if (list_A[i] < list_B[j]) {
        interations++;

        i++;
      } else {
        interations++;
        j++;
      }
    }
  }

  return 0;
}