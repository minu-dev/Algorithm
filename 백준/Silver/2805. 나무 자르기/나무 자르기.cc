#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long int n, m, max = LONG_MIN;
long int result = LONG_MIN;
void binarySearch(long int *tree, long int left, long int right) {
  long int total, mid, cutMax;
  while (left <= right) {
    total = 0;
    mid = (left + right) / 2;
    for (int i = 0; i < n; i++) {
      if (tree[i] > mid)
        total += tree[i] - mid;
    }
    if (total < m)
      right = mid - 1;
    else {
      if (mid > result)
        result = mid;
      left = mid + 1;
    }
  }
}

int main() {
  scanf("%ld %ld", &n, &m);
  long int *tree = (long int *)malloc(sizeof(long int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%ld", &tree[i]);
    if (tree[i] > max)
      max = tree[i];
  }
  binarySearch(tree, 0, max);
  printf("%ld\n", result);
  return 0;
}