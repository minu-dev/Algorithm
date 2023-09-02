#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  char str[MAX];
  int count = 0;
  scanf("%[^\n]", str);

  char *token = strtok(str, " ");

  while (token != NULL) {
    token = strtok(NULL, " ");
    count++;
  }

  printf("%d\n", count);

  return 0;
}