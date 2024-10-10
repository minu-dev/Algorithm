#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  short *arr = (short *)malloc(sizeof(short) * (n + 1));
  long long *sum = (long long *)malloc(sizeof(long long) * (n + 1));
  arr[0] = sum[0] = 0;
  for (int k = 1; k <= n; k++)
    scanf("%hd", &arr[k]);
  sum[1] = arr[1];
  for (int k = 2; k <= n; k++)
    sum[k] = sum[k - 1] + arr[k];
  for (int k = 0; k < m; k++) {
    int i, j;
    scanf("%d %d", &i, &j);
    printf("%lld\n", sum[j] - sum[i - 1]);
  }
  return 0;
}