#include <bits/stdc++.h>
using namespace std;

int interations = 0;
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int euclid_gcd(int m, int n) {
  int r;
  if (n == 0) {
    interations++;
    return m;
  }
  r = m % n;
  m = n;
  n = r;
  interations++;
  euclid_gcd(m, n);
}
int cic_gcd(int m, int n) {
  int t = min(m, n);
  while ((m % t != 0) || (n % t != 0)) {
    t--;
  }

  return t;
}

int euclid_sub_gcd(int m, int n) {
  int r;
  int local_m = max(m, n);
  int local_n = min(m, n);
  if (local_n == 0) {
    return m;
  }

  r = local_m - local_n;
  local_m = local_n;
  local_n = r;
  euclid_sub_gcd(local_m, local_n);
}

int main() {
  int a = 9;
  int b = 2;
  int teste = euclid_sub_gcd(a, b);
  
  
  return 0;
}