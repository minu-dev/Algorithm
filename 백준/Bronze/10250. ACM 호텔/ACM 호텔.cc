#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  int T, H, W, N;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    scanf("%d %d %d", &H, &W, &N);
    int x = N / H + 1;
    int y = N % H * 100;
    if (y == 0) {
      x--;
      y = H * 100;
    }
    printf("%d\n", x + y);
  }

  return 0;
}