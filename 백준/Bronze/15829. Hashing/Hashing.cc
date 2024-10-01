#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 31
#define M 1234567891

int main() {
  int L, hash = 0;
  scanf("%d", &L);
  char *str = (char *)malloc(L * sizeof(char));
  scanf("%s", str);
  for (int i = 0; i < strlen(str); i++)
    hash += (str[i] - 96) * pow(R, i);
  //알파벳 소문자는 아스키번호 97부터 시작이므로
  // 96을 빼주어 a가 1, b가 2, c가 3 ... 이 되도록 함
  hash %= M;
  printf("%d\n", hash);
  return 0;
}