#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int lowerUpperRand(int lower, int upper) {
  return rand() % (upper - lower + 1) + lower;
}
int main() {
  FILE *output;
  const int max_value = 40000;
  int qnt = 30;
  int upper = 40000;
  int lower = 0;
  output = fopen("teste2.txt", "w");
  if (output == NULL) {
    return 1;
  }
  for (int i = 0; i < qnt; i++) {
    int random_value = rand() % 10000;
    fprintf(output, "%d\n", random_value);
    for (int j = 0; j < random_value; j++)
      // fprintf(output, "%d %d\n", rand() % max_value, rand() % max_value);
      fprintf(output, "%d %d\n", lowerUpperRand(lower,upper),lowerUpperRand(lower,upper));
  }

  fprintf(output, "0");
  return 0;
}