#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//조합의 원소 개수
#define SIZE 3

int result[SIZE] = {0, 0, 0};
int max = INT_MIN;

void Combination(int *arr, int *result, int r, int index, int depth, int N,
                 int M) {
  if (r == 0) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
      sum += result[i];
    if (sum > max && sum <= M)
      max = sum;
  } else if (depth == N)
    return;
  else {
    result[index] = arr[depth];
    //어떤 원소를 뽑은 경우
    Combination(arr, result, r - 1, index + 1, depth + 1, N, M);
    //뽑지 않은 경우
    Combination(arr, result, r, index, depth + 1, N, M);
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int *arr = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);
  Combination(arr, result, SIZE, 0, 0, N, M);
  printf("%d\n", max);
}