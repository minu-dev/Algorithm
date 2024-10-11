#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_MAX 25
#define STRING_MAX 51

typedef struct Queue {
  int front, rear;
  char data[QUEUE_MAX][STRING_MAX];
} Queue;

void initQueue(Queue *q) {
  q->front = q->rear = -1;
  for (int i = 0; i < QUEUE_MAX; i++)
    sprintf(q->data[i], "%s", "\0");
}

int isEmpty(Queue *q) { return q->front == q->rear; }

int isFull(Queue *q) { return q->rear == QUEUE_MAX - 1; }

void enqueue(Queue *q, char *data) {
  if (isFull(q))
    exit(0);
  sprintf(q->data[++q->rear], "%s", data);
  return;
}

char *dequeue(Queue *q) {
  if (isEmpty(q))
    exit(0);
  return q->data[++q->front];
}

int main() {
  char str[STRING_MAX];
  Queue q;
  int sum = 0;
  initQueue(&q);
  scanf("%s", str);
  char *ptr = strtok(str, "-");
  while (ptr != NULL) {
    enqueue(&q, ptr);
    ptr = strtok(NULL, "-");
  }
  // 첫 마이너스가 나오기 전까지의 수들 양수로 처리
  if (!isEmpty(&q)) {
    char *ptr = strtok(dequeue(&q), "+");
    while (ptr != NULL) {
      sum += atoi(ptr);
      ptr = strtok(NULL, "+");
    }
  }

  // 마이너스가 나온 이후의 수들 음수로 처리
  while (!isEmpty(&q)) {
    char *ptr = strtok(dequeue(&q), "+");
    while (ptr != NULL) {
      sum -= atoi(ptr);
      ptr = strtok(NULL, "+");
    }
  }

  printf("%d\n", sum);
  return 0;
}