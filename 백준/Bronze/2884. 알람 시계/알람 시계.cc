#include <stdio.h>

int main() {
  int h, m, k = 0;
  scanf("%d %d", &h, &m);
  k = m - 45;
  if (k < 0) {
    h--;
    m = 60 + k;
    if (h < 0)
      h += 24;
  } else
    m -= 45;
  printf("%d %d\n", h, m);
  return 0;
}