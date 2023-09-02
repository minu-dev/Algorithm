#include <stdio.h>

int main() {
  int num[9];
  int max = 0, maxIndex = 0;
  for (int i = 0; i < 9; i++) {
    scanf("%d", &num[i]);
  }
  for (int i = 0; i < 9; i++) {
    if (num[i] > max) {
      max = num[i];
      maxIndex = i + 1;
    }
  }
  printf("%d\n%d\n", max, maxIndex);
}