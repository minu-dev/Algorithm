#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // 초기화
  int fibo[2][41] = {
      0,
  };
  fibo[0][0] = 1;
  fibo[1][0] = 0;
  fibo[0][1] = 0;
  fibo[1][1] = 1;

  for (int i = 2; i <= 40; i++) {
    fibo[0][i] = fibo[0][i - 1] + fibo[0][i - 2];
    fibo[1][i] = fibo[1][i - 1] + fibo[1][i - 2];
  }

  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%d %d\n", fibo[0][n], fibo[1][n]);
  }
  return 0;
}