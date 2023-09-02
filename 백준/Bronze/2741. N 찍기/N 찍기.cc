#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d\n", i);
  }

  return 0;
}