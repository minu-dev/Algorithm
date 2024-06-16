#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int arrA[64] = {
      0,
  };
  int arrB[64] = {
      0,
  };

  int cnt = 0;
  for (int i = 1; i <= a; i++) {
    if (a % i == 0) {
      arrA[cnt++] = i;
    };
  }
  for (int i = 1; i <= b; i++) {
    if (b % i == 0) {
      arrB[cnt++] = i;
    };
  }

  int max = 0;
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      if (arrA[i] == arrB[j]) {
        if (max < arrA[i]) {
          max = arrA[i];
        }
      }
    }
  }

  int low = a * b;
  for (int i = low; i >= 1; i--) {
    if (i % a == 0 && i % b == 0)
      low = i;
  }

  printf("%d\n%d\n", max, low);
}