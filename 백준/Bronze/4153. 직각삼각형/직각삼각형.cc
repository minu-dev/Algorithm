#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int static compare(const void *a, const void *b) {
  if (*(int *)a > *(int *)b)
    return 1;
  else if (*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
}

int main() {
  int len[3] = {
      0,
  };
  while (1) {
    for (int i = 0; i < 3; i++) {
      scanf("%d", &len[i]);
    }
    if (len[0] == 0 && len[1] == 0 && len[2] == 0)
      break;
    qsort(len, sizeof(len) / sizeof(int), sizeof(int), compare);
    if (len[0] * len[0] + len[1] * len[1] == len[2] * len[2])
      printf("right\n");
    else
      printf("wrong\n");
  }
  return 0;
}