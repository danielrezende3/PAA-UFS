#include <bits/stdc++.h>
using namespace std;
int sequential_search(int *lista, int tamanho, int procurado) {
  int i = 0;
  while (i < tamanho && lista[i] != procurado) {
    i = i + 1;
  }
  if (i < tamanho) {
    return i;
  } else {
    return -1;
  }
}
int main() {
  int list[] = {3, 5, 8, 7, 9, 2, 4, 6};
  int tamanho = sizeof(list) / sizeof(int);
  cout << sequential_search(list, tamanho, 4) << endl;
  return 0;
}