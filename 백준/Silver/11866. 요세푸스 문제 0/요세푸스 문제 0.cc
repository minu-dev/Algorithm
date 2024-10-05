#include <stdio.h>
#include <stdlib.h>

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

int main() {
  int n, k;
  Queue queue;
  initQueue(&queue);
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    enqueue(&queue, i + 1);
  printf("<");
  while (size(&queue) > 0) {
    for (int i = 0; i < k - 1; i++)
      enqueue(&queue, dequeue(&queue));
    printf("%d", dequeue(&queue));
    if (size(&queue) > 0)
      printf(", ");
  }
  printf(">\n");
  return 0;
}