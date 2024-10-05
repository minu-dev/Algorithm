#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int static compare(const void *first, const void *second) {
  if (*(int *)first > *(int *)second)
    return 1;
  else if (*(int *)first > *(int *)second)
    return -1;
  else
    return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  int *arr = (int *)malloc(sizeof(int) * (n + 1));
  arr[0] = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);
  qsort(arr, n + 1, sizeof(int), compare);
  int startIdx = round(n * 0.15) + 1;
  int lastIdx = n - round(n * 0.15);
  float difficulty = 0;
  for (int i = startIdx; i <= lastIdx; i++) {
    difficulty += arr[i];
  }
  difficulty /= lastIdx - startIdx + 1;
  difficulty = round(difficulty);
  printf("%.0f\n", difficulty);
  return 0;
}