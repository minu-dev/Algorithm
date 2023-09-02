#include <stdio.h>
#define MAX 100

int main() {
  int N;
  scanf("%d", &N);
  while (N > 0) {
    N -= 4;
    printf("long ");
  }
  printf("int\n");
  return 0;
}