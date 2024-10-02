#include <math.h>
#include <stdio.h>

int factorial(int a) {
  if (a != 1)
    return a * factorial(a - 1);
  else
    return 1;
}

int main() {
  int n, k;
  int bicoef = 0;
  scanf("%d %d", &n, &k);
  if (n == k || k == 0)
    printf("1\n");
  else
    printf("%d\n", factorial(n) / (factorial(n - k) * factorial(k)));
  return 0;
}