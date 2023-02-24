#include <stdio.h>

struct Ator {
  int idade;
  int quantidade;
};

void leVetor(struct Ator v[], int tam) {
  int i;
  for (i = 0; i < tam; i++) scanf("%d%d", &v[i].idade, &v[i].quantidade);
}

void geraRel(struct Ator a[], int tamA, struct Ator b[], int tamB) {
  int i, j;
  i = 0, j = 0;
  while (i < tamA && j < tamB) {
    if (a[i].idade < b[j].idade) {
      printf("%i - %i\n", a[i].idade, a[i].quantidade);
      i++;
    } else if (a[i].idade > b[j].idade) {
      printf("%i - %i\n", b[j].idade, b[j].quantidade);
      j++;
    } else if (a[i].idade == b[j].idade) {
      printf("%i - %i\n", b[j].idade, b[j].quantidade + a[i].quantidade);
      i++;
      j++;
    }
  }
  for (int k = i; k < tamA; k++) {
    printf("%i - %i\n", a[k].idade, a[k].quantidade);
  }
  for (int k = j; k < tamB; k++) {
    printf("%i - %i\n", b[k].idade, b[k].quantidade);
  }
}

int main() {
  struct Ator grupoA[100], grupoB[100];
  int tamGrupoA, tamGrupoB;
  scanf("%d%d", &tamGrupoA, &tamGrupoB);
  leVetor(grupoA, tamGrupoA);
  leVetor(grupoB, tamGrupoB);
  geraRel(grupoA, tamGrupoA, grupoB, tamGrupoB);
  return 0;
}