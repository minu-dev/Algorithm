#include <stdio.h>
#include <stdlib.h>

int people(int n, int k) {
  int sum = 0;
  if (n == 0)
    return k;
  else {
    for (int i = 1; i <= k; i++) {
      sum += people(n - 1, i);
    }
    return sum;
  }
}

int main() {
  int t, n, k;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &n, &k);
    printf("%d\n", people(n, k));
  }
}