#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100000

int stack[MAX_STACK_SIZE] = {
    0,
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

void push(int value) {
  if (!IsFull())
    stack[++top] = value;
}

int pop() {
  if (!IsEmpty()) {
    int tmp = stack[top];
    stack[top--] = 0;
    return tmp;
  } else
    return 0;
}

int main() {
  int k;
  int n;
  int sum = 0;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &n);
    if (n == 0)
      pop();
    else
      push(n);
  }
  while (!IsEmpty())
    sum += pop();
  printf("%d", sum);
  return 0;
}
