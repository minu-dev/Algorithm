#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  int _5kg = 0, _3kg = 0;
  scanf("%d", &n);
  if (n % 5 == 0)
    printf("%d\n", n / 5);
  else {
    if (n == 4)
      printf("-1\n");
    else if (n == 3)
      printf("1\n");
    else {
      for (_5kg = (n - (n % 5)) / 5; _5kg >= 0; _5kg--) {
        if ((n - _5kg * 5) % 3 == 0) {
          _3kg = (n - _5kg * 5) / 3;
          printf("%d", _5kg + _3kg);
          return 0;
        }
      }
      printf("-1\n");
    }
  }
  return 0;
}