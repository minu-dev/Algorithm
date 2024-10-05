#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  int num[5] = {
      0,
  };
  int val = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%d", &num[i]);
  }

  for (int i = 0; i < 5; i++) {
    val += num[i] * num[i];
  }

  printf("%d\n", val % 10);

  return 0;
}