#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main() {
  char str[MAX];
  int i;
  scanf("%s %d", str, &i);
  printf("%c\n", str[i - 1]);

  return 0;
}