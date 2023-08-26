#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int K, N;
  long long lan[10000];
  long long max = LLONG_MIN;
  long long length = LLONG_MIN;

  scanf("%d %d", &K, &N);

  for (int i = 0; i < K; i++) {
    scanf("%lld", &lan[i]);
    if (lan[i] > max)
      max = lan[i];
  }

  long long left, mid, right, cnt;
  left = 1;
  right = max;

  while (left <= right) {
    mid = (left + right) / 2;
    cnt = 0;
    for (long long i = 0; i < K; i++) {
      cnt += lan[i] / mid;
    }
    if (cnt >= N && length < mid)
      length = mid;
    if (cnt < N)
      right = mid - 1;
    else
      left = mid + 1;
  }

  printf("%lld\n", length);

  return 0;
}