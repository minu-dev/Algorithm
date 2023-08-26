#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  int multiple_5 = 0;
  int multiple_25 = 0;
  int multiple_125 = 0;

  scanf("%d", &N);

  multiple_5 = N / 5;
  multiple_25 = N / 25;
  multiple_125 = N / 125;

  printf("%d\n", multiple_5 + multiple_25 + multiple_125);

  return 0;
}