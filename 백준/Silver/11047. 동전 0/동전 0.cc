#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, k;
  int cnt = 0;
  scanf("%d %d", &n, &k);
  int *coin = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    scanf("%d", &coin[i]);
  for (int i = n - 1; i >= 0; i--) {
    if (coin[i] <= k) {
      cnt += k / coin[i];
      k %= coin[i];
    }
  }
  printf("%d\n", cnt);

  return 0;
}