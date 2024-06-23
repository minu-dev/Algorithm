#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

void ClearLineFromReadBuffer(void) {
  while (getchar() != '\n')
    ;
}

typedef struct stack {
  char data[MAX_SIZE];
  int top;
} Stack;

void initStack(Stack *stack) {
  stack->top = -1;
  for (int i = 0; i < MAX_SIZE; i++) {
    stack->data[i] = '\0';
  }
}

bool isFull(Stack *stack) {
  if (stack->top >= MAX_SIZE - 1)
    return true;
  else
    return false;
}

bool isEmpty(Stack *stack) {
  if (stack->top < 0)
    return true;
  else
    return false;
}

void push(Stack *stack, char value) {
  if (!isFull(stack)) {
    stack->data[++stack->top] = value;
  }
}

char pop(Stack *stack) {
  if (!isEmpty(stack)) {
    return stack->data[stack->top--];
  } else
    return false;
}

int main() {
  int N;
  scanf("%d", &N);

  // N 개의 스택 동적 선언
  Stack *stack = (Stack *)malloc(sizeof(Stack) * N);

  //초기화
  for (int i = 0; i < N; i++)
    initStack(&stack[i]);

  // N 개의 문자열 입력 받기
  for (int i = 0; i < N; i++) {
    bool VPS = true;

    char str[MAX_SIZE];
    scanf("%s", str);
    ClearLineFromReadBuffer();

    // 문자열 길이만큼 스택에 넣기
    for (int j = 0; j < strlen(str); j++) {
      if (str[j] == '(') {
        push(&stack[i], str[j]);
      } else if (str[j] == ')') {
        char tmp = pop(&stack[i]);
        if (tmp == false) {
          VPS = false;
          break;
        } else
          continue;
      }
    }
    if (VPS == true)
      VPS = isEmpty(&stack[i]);
    VPS ? printf("YES\n") : printf("NO\n");
  }
}