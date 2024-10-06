#include <stdio.h>

int main() {
  int dice[3];
  int max = 0;
  int k = 0;
  int same = 0;
  scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);
  for (int i = 0; i < 3; i++) {
    k = 0;
    for (int j = 0; j < 3; j++) {
      if (dice[i] == dice[j]) {
        k++;
        if (i != j)
          same = dice[j];
      }
    }
    if (k > max)
      max = k;
  }
  switch (max) {
  case 1:
    k = 0;
    for (int i = 0; i < 3; i++) {
      if (dice[i] > k)
        k = dice[i];
    }
    printf("%d\n", k * 100);
    return 0;
  case 2:
    printf("%d\n", 1000 + same * 100);
    return 0;
  case 3:
    printf("%d\n", 10000 + dice[0] * 1000);
    return 0;
  default:
    return 0;
  }
  return 0;
}