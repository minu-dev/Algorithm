#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int N;
  float score[1000] = {
      0,
  };
  int max = INT_MIN;
  float sum = 0;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%f", &score[i]);
  }

  for (int i = 0; i < N; i++) {
    if (score[i] > max) {
      max = score[i];
    }
  }

  for (int i = 0; i < N; i++) {
    score[i] = score[i] / max * 100;
    sum += score[i];
  }

  printf("%g\n", sum / N);

  return 0;
}