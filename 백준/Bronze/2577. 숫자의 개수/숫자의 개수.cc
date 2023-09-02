#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  int n[3] = {
      0,
  };
  int count[10] = {
      0,
  };

  for (int i = 0; i < 3; i++) {
    scanf("%d", &n[i]);
  }

  char result[10];
  sprintf(result, "%d", n[0] * n[1] * n[2]);

  for (int i = 0; i < 10; i++) {
    count[result[i] - '0']++;
  }

  for (int i = 0; i < 10; i++) {
    printf("%d\n", count[i]);
  }
}