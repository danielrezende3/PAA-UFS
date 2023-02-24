#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int qnt;
  while (scanf("%d", &qnt) != EOF) {
    int arr[101] = {};
    for (int i = 0; i < qnt; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      for (int j = x; j <= y; j++) {
        arr[j]++;
      }
    }
    int find;
    scanf("%d", &find);
    int sum = 0;
    for (int i = 0; i < find; i++) {
      sum += arr[i];
    }
    if (arr[find] == 0) {
      printf("%d nao encontrado\n", find);
    } else {
      printf("%d encontrado de %d a %d\n", find, sum, sum + arr[find] - 1);
    }
  }
  return 0;
}