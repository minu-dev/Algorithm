#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second) {
  return *(int *)first - *(int *)second;
}

int findAvg(int N, int *M) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += M[i];
  }
  return (int)round((float)sum / N);
}

int findMid(int N, int *M) {
  qsort(M, N, sizeof(int), compare);
  return M[N / 2];
}

int findMode(int N, int *M) {
  int ar[8001] = {0};
  int i, idx, max = 0, cnt = 0;

  for (i = 0; i < N; i++) {
    idx = M[i] + 4000;
    ar[idx] += 1;

    if (ar[idx] > max)
      max = ar[idx];
  }

  for (i = 0, idx = 0; i < 8001; i++) {
    if (ar[i] == 0)
      continue;

    if (ar[i] == max) {
      if (cnt == 0) {
        idx = i;
        cnt += 1;
      } else if (cnt == 1) {
        idx = i;
        break;
      }
    }
  }
  return idx - 4000;
}

int findRange(int N, int *M) {
  int max = INT_MIN;
  int min = INT_MAX;

  for (int i = 0; i < N; i++) {
    if (M[i] > max)
      max = M[i];
    if (M[i] < min)
      min = M[i];
  }

  return max - min;
}

int main(void) {
  int N;
  int M[500001] = {
      0,
  };

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &M[i]);
  }

  printf("%d\n%d\n%d\n%d", findAvg(N, M), findMid(N, M), findMode(N, M),
         findRange(N, M));
}