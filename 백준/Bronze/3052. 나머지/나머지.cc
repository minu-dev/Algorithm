#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  int num[10] = {
      0,
  };
  int remainder[10] = {
      0,
  };
  int count = 0;

  for (int i = 0; i < 10; i++) {
    scanf("%d", &num[i]);
    remainder[i] = num[i] % 42;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (remainder[i] == -1)
        continue;
      else if (remainder[i] == remainder[j]) {
        remainder[j] = -1;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    if (remainder[i] != -1)
      count++;
  }

  printf("%d\n", count);

  return 0;
}