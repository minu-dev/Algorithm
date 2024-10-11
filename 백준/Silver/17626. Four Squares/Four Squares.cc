#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50001
#define MIN(A, B) (A < B) ? A : B

int main() {
  int dp[MAX_SIZE] = {
      0,
      1,
  };
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 1; j * j <= i; j++) {
      dp[i] = MIN(dp[i], dp[i - (j * j)] + 1);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}