#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Adicionalmente, o INEP terá o cuidado de lhe entregar a sequência dos CPFs
// ordenada de forma ascendente.

typedef struct Inscrito {
  int CPF;
  int nota;
} Inscrito;

int binarySearch(Inscrito *candidato, int tamanho, int valor) {
  int left, mid, right;
  left = 0;
  right = tamanho - 1;
  while (left <= right) {
    mid = floor((left + right) / 2);
    if (valor == candidato[mid].CPF)
      return mid;
    else if (valor < candidato[mid].CPF)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}
int main() {
  int total_inscritos;
  int valor;
  scanf("%d", &total_inscritos);
  Inscrito *candidato = (Inscrito *)malloc(total_inscritos * sizeof(Inscrito));
  for (int i = 0; i < total_inscritos; i++) {
    scanf("%d", &valor);
    candidato[i].CPF = valor;
  }
  for (int i = 0; i < total_inscritos; i++) {
    scanf("%d", &valor);
    candidato[i].nota = valor;
  }
  int testes;
  scanf("%d", &testes);
  for (int i = 0; i < testes; i++) {
    scanf("%d", &valor);
    valor = binarySearch(candidato, total_inscritos, valor);
    if (valor != -1)
      printf("%d\n", candidato[valor].nota);
    else
      printf("NAO SE APRESENTOU\n");
  }

  return 0;
}
// 6 qnt de candidatos
// 2 cpf
// 4 cpf
// 8 cpf
// 10 cpf
// 15 cpf
// 17 cpf
// 700 nota
// 100 nota
// 300 nota
// 900 nota
// 750 nota
// 780 nota
// 3 teste
// 10 CPF
// 5 cpf
// 4 cpf