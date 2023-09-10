#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int M, count = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &M);
    for (int j = 2; j <= M; j++) {
      if (M == j)
        count++;
      if (M % j == 0)
        break;
    }
  }

  printf("%d", count);

  return 0;
}