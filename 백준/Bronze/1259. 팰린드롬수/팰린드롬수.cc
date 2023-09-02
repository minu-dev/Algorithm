#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[6];
  char rev[6];

  while (1) {
    scanf("%s", str);
    if (!strcmp(str, "0"))
      break;
    int len = strlen(str);
    strcpy(rev, str);
    for (int i = 0; i < len / 2; i++) {
      char tmp;
      tmp = rev[i];
      rev[i] = rev[len - 1 - i];
      rev[len - 1 - i] = tmp;
    }
    if (!strcmp(str, rev))
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}