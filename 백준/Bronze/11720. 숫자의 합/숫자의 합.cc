#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main() {
  int N;
  char str[MAX];
  int sum = 0;

  scanf("%d %s", &N, str);
  for (int i = 0; i < N; i++) {
    sum += str[i] - '0'; // 0의 아스키 코드 값을 빼줌
  }
  printf("%d\n", sum);

  return 0;
}