#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10000
#define MAX_STRING_LENGTH 15

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *front;
  Node *rear;
  int count;
} Queue;

void initQueue(Queue *queue) {
  queue->front = queue->rear = NULL;
  queue->count = 0;
}

int isEmpty(Queue *queue) { return queue->count == 0; }

void enqueue(Queue *queue, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if (isEmpty(queue))
    queue->front = newNode;
  else
    queue->rear->next = newNode;
  queue->rear = newNode;
  queue->count++;
}

int dequeue(Queue *queue) {
  int data;
  Node *ptr;
  if (isEmpty(queue))
    return -1;
  ptr = queue->front;
  data = ptr->data;
  queue->front = ptr->next;
  free(ptr);
  queue->count--;
  return data;
}

int size(Queue *queue) { return queue->count; }

int front(Queue *queue) {
  if (isEmpty(queue))
    return -1;
  else
    return queue->front->data;
}

int back(Queue *queue) {
  if (isEmpty(queue))
    return -1;
  else
    return queue->rear->data;
}

int main() {
  int n;
  char str[MAX_STRING_LENGTH];
  Queue q;
  initQueue(&q);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    if (strcmp(str, "push") == 0) {
      int tmp;
      scanf("%d", &tmp);
      enqueue(&q, tmp);
    } else if (strcmp(str, "pop") == 0)
      printf("%d\n", dequeue(&q));
    else if (strcmp(str, "empty") == 0)
      printf("%d\n", isEmpty(&q));
    else if (strcmp(str, "front") == 0)
      printf("%d\n", front(&q));
    else if (strcmp(str, "back") == 0)
      printf("%d\n", back(&q));
    else if (strcmp(str, "size") == 0)
      printf("%d\n", size(&q));
  }
  return 0;
}