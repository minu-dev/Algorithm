#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000
#define STRING_LENGTH 13

int stack[MAX_STACK_SIZE] = {
    0,
};
int top = -1;

int empty() {
  if (top < 0)
    return 1;
  else
    return 0;
}

int full() {
  if (top >= MAX_STACK_SIZE - 1)
    return 1;
  else
    return 0;
}

void push(int value) {
  if (!full())
    stack[++top] = value;
}

int pop() {
  if (!empty()) {
    int tmp = stack[top];
    stack[top--] = 0;
    return tmp;
  } else
    return -1;
}

int size() { return top + 1; }

int Top() {
  if (!empty())
    return stack[top];
  else
    return -1;
}

int main() {
  int n;
  char str[STRING_LENGTH] = {
      '\0',
  };
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    fgets(str, STRING_LENGTH, stdin);
    if (strncmp(str, "push", 4) == 0) {
      char tmp[STRING_LENGTH];
      sprintf(tmp, "%s", &str[5]);
      tmp[strlen(tmp) - 1] = '\0'; //개행 문자를 널 문자로 변환
      push(atoi(tmp));
    } else if (strcmp(str, "pop\n") == 0)
      printf("%d\n", pop());
    else if (strcmp(str, "size\n") == 0)
      printf("%d\n", size());
    else if (strcmp(str, "empty\n") == 0)
      printf("%d\n", empty());
    else if (strcmp(str, "top\n") == 0)
      printf("%d\n", Top());
    fflush(stdin);
  }
  return 0;
}