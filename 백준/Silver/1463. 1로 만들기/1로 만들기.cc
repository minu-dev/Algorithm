#include <stdio.h>
#include <stdlib.h>
#define MIN(A, B) (A < B) ? A : B

int find(int n) {
  if (n == 1)
    return 0;
  int x[1000001];
  int i = 4;
  x[2] = 1, x[3] = 1;
  while (i <= n) {
    x[i] = x[i - 1] + 1;
    if (i % 3 == 0)
      x[i] = MIN(x[i], x[i / 3] + 1);
    if (i % 2 == 0)
      x[i] = MIN(x[i], x[i / 2] + 1);
    i++;
  }
  return x[n];
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", find(n));
  return 0;
}