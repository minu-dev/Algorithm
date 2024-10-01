#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1234567891

int main() {
  int L;
  long long unsigned int R = 1;
  long long unsigned int hash = 0;
  scanf("%d", &L);
  char *str = (char *)malloc(L * sizeof(char));
  scanf("%s", str);
  for (int i = 0; i < strlen(str); i++) {
    hash += (long long unsigned int)(str[i] - 96) * R;
    //알파벳 소문자는 아스키번호 97부터 시작이므로
    // 96을 빼주어 a가 1, b가 2, c가 3 ... 이 되도록 함
    R *= 31;
    R %= M;
    //★ 핵심 ★ R을 거듭제곱 한 후, 너무 커지기 전에 mod M 연산 수행함
  }
  hash %= M;
  printf("%lld\n", hash);
  return 0;
}
