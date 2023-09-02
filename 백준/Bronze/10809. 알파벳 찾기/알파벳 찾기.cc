#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  char str[100];
  int ck = 0;

  scanf("%s", str);

  for (int i = 0; i < 26; i++) {
    int len = strlen(str);
    for (int j = 0; j < len; j++) {
      if (i + 97 == str[j]) {
        printf("%d ", j);
        ck = 1;
        break;
      }
    }
    if (ck == 0)
      printf("-1 ");
    else
      ck = 0;
  }
  printf("\n");

  return 0;
}