#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  char str[MAX];
  int count[26] = {
      0,
  };
  int index = 0;
  int max = INT_MIN;

  scanf("%s", str);
  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
    count[str[i] - 65]++;
  }

  int check = 0;

  for (int i = 0; i < 26; i++) {
    if (count[i] > max && count[i] != 0) {
      index = i;
      check = 1;
      max = count[i];
    } else if (count[i] == max && max != 0) {
      check++;
    }
  }
  if (check == 1) {
    printf("%c\n", index + 65);
  } else
    printf("?\n");

  return 0;
}