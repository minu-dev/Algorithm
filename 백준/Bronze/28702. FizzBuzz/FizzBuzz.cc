#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Detector(char *str) {
  if (atoi(str) != 0)
    return 1; // 숫자인 경우
  else
    return 0; // 숫자가 아닌 경우
  // 입력이 1 이상의 자연수가 들어오므로, 0을 고려할 필요가 없음
}

char *FizzBuzz(int n) {
  if (n % 15 == 0)
    return "FizzBuzz\n";
  else if (n % 3 == 0 && n % 5 != 0)
    return "Fizz\n";
  else if (n % 3 != 0 && n % 5 == 0)
    return "Buzz\n";
  else {
    char *str = (char *)malloc(sizeof(char) * 8);
    sprintf(str, "%d", n);
    return str;
  }
}

int main() {
  char str[3][8] = {
      "\0 ",
  };
  for (int i = 0; i < 3; i++) {
    scanf("%s", str[i]);
  }

  //마지막이 숫자일 때
  if (Detector(str[2]))
    printf("%s", FizzBuzz(atoi(str[2]) + 1));
  //중간이 숫자일 때
  else if (Detector(str[1]))
    printf("%s", FizzBuzz(atoi(str[1]) + 2));
  //처음이 숫자일 때
  else if (Detector(str[0]))
    printf("%s", FizzBuzz(atoi(str[0]) + 3));

  return 0;
}