#include <stdio.h>

int main() {
  int N, value, i, count;
  i = 0;
  count = 0;
  scanf("%d", &N);
  while (scanf("%d", &value) && value != -1 && i < 19) {
    if (value == N) {
      count++;
    }
    i++;
  }
  printf("%d aparece %d vezes", N, count);

  return 0;
}
