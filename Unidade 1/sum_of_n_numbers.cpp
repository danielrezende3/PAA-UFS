#include <bits/stdc++.h>
using namespace std;

int sum_all_numbers(int *list, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += list[i];
  }
  return sum;
}
int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  return 0;
}