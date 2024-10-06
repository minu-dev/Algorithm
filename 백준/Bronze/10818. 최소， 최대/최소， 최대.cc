#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main() {
  int N;
  int num[MAX];
  int min = INT_MAX, max = INT_MIN;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num[i]);
  }
  for (int i = 0; i < N; i++) {
    if (num[i] < min)
      min = num[i];
    if (num[i] > max)
      max = num[i];
  }

  printf("%d %d\n", min, max);
  return 0;
}