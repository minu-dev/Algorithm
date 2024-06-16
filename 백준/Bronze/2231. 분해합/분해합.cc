#include <math.h>
#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int sum = 0;

  for (int i = 1; i < N; i++) {
    sum = 0;
    int tmp = i;
    for (int j = 0; j < 7; j++) {
      sum += tmp / (1000000 / (int)pow(10, j));
      tmp %= (1000000 / (int)pow(10, j));
    }
    if (sum + i == N) {
      printf("%d\n", i);
      return 0;
    }
  }

  printf("0\n");

  return 0;
}