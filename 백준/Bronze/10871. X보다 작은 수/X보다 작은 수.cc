#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int main() {
  int N, X;
  int A[MAX] = {
      0,
  };

  scanf("%d %d", &N, &X);

  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < N; i++) {
    if (A[i] < X)
      printf("%d ", A[i]);
  }
  printf("\n");

  return 0;
}