#include <bits/stdc++.h>
using namespace std;
// Only works with integers, with doenst have result, gives 0.eE
int my_sqrt(int x) {
  int result = 0;
  for (int i = 0; i < x; i++) {
    if (i * i == x) {
      result = i;
      break;
    } else if (i * i > x) {
      break;
    }
  }
  return result;
}
int main() {
  cout << sqrt(30) << endl;
  return 0;
}