#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 101

int main() {
  int t, n;
  long long int arr[MAX_COUNT] = {
      1,
      1,
      1,
  };
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 3; j < n; j++)
      arr[j] = arr[j - 2] + arr[j - 3];
    printf("%lld\n", arr[n - 1]);
  }
  return 0;
}