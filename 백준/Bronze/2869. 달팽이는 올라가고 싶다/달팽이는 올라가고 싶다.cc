#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, v, day;
  scanf("%d %d %d", &a, &b, &v);
  if ((v - b) % (a - b) == 0)
    day = (v - b) / (a - b);
  else
    day = (v - b) / (a - b) + 1;
  // day = (v - b - 1) / (a - b) + 1;
  // 이게 더 깔끔한 풀이지만, -1을 해주는 이유가 이해가 되지 않기 때문에 내가 쓴
  // 답으로 채택하지 않음.
  printf("%d\n", day);
}