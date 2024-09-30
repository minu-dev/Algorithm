#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, T, P = 0;
  int tshirtBundle = 0;
  int size[6] = {
      0,
  };
  scanf("%d", &N);
  for (int i = 0; i < sizeof(size) / sizeof(int); i++)
    scanf("%d", &size[i]);
  scanf("%d %d", &T, &P);
  for (int i = 0; i < sizeof(size) / sizeof(int); i++) {
    if (size[i] != 0) {
      if (size[i] % T == 0)
        tshirtBundle += size[i] / T;
      else
        tshirtBundle += size[i] / T + 1;
    }
  }
  printf("%d\n", tshirtBundle);
  printf("%d %d\n", N / P, N % P);
  return 0;
}