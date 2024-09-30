#include <stdio.h>

int main() {
  int n = 0;
  int borderEnd = 1;
  int cnt = 1;
  scanf("%d", &n);
  while (n > borderEnd)
    borderEnd += 6 * cnt++;
  printf("%d\n", cnt);
  return 0;
}