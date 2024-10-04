#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 102

char stack[MAX_STACK_SIZE] = {
    '\0',
};
int top = -1;

int IsEmpty() {
  if (top < 0)
    return 1;
  else
    return 0;
}

int IsFull() {
  if (top >= MAX_STACK_SIZE - 1)
    return 1;
  else
    return 0;
}

void push(char value) {
  if (!IsFull())
    stack[++top] = value;
}

char pop() {
  if (!IsEmpty()) {
    char tmp = stack[top];
    stack[top--] = '\0';
    return tmp;
  } else
    return 0;
}

void initStack() {
  for (int i = 0; i < MAX_STACK_SIZE; i++)
    stack[i] = '\0';
  top = -1;
}

int main() {
  char str[MAX_STACK_SIZE] = "\0";
  bool isFalse = false;
  while (1) {
    fgets(str, MAX_STACK_SIZE, stdin);
    if (strcmp(str, ".\n") == 0)
      return 0;
    for (int i = 0; i < strlen(str); i++) {
      if (str[i] == '(')
        push('(');
      else if (str[i] == '[')
        push('[');
      else if (str[i] == ')') {
        if (pop() == '(')
          continue;
        else {
          isFalse = true;
          break;
        }
      } else if (str[i] == ']') {
        if (pop() == '[')
          continue;
        else {
          isFalse = true;
          break;
        }
      }
    }
    if (isFalse)
      printf("no\n");
    else if (IsEmpty())
      printf("yes\n");
    else
      printf("no\n");
    initStack();
    isFalse = false;
  }
  return 0;
}