#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  b += c;
  while (b >= 60) {
    b -= 60;
    a++;
    if (a >= 24)
      a -= 24;
  }
  printf("%d %d\n", a, b);
  return 0;
}