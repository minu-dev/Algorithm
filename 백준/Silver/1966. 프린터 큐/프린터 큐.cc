#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int priority;
  int wonder;
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

void enqueue(Queue *queue, int priority, int wonder) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->priority = priority;
  newNode->wonder = wonder;
  newNode->next = NULL;

  if (isEmpty(queue))
    queue->front = newNode;
  else
    queue->rear->next = newNode;

  queue->rear = newNode;
  queue->count++;
}

int dequeue(Queue *queue) {
  Node *ptr;
  int wonder;
  if (!isEmpty(queue)) {
    ptr = queue->front;
    wonder = ptr->wonder;
    queue->front = ptr->next;
    free(ptr);
    queue->count--;
  }
  return wonder;
}

int compare(Queue *queue) {
  Node *ptr;
  int max_priority = INT_MIN;
  if (!isEmpty(queue)) {
    ptr = queue->front;
    while (ptr->next != NULL) {
      if (ptr->priority > max_priority)
        max_priority = ptr->priority;
      ptr = ptr->next;
    }
    if (ptr->priority > max_priority)
      max_priority = ptr->priority;
    ptr = queue->front;
    if (ptr->priority < max_priority) {
      queue->front = ptr->next;
      queue->rear->next = ptr;
      queue->rear = ptr;
      ptr->next = NULL;
      return 0;
    }
  }
  return 1;
}

int main() {
  int T, N, M;
  int priority[101] = {
      0,
  };
  Queue queue;
  int count = 1;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    initQueue(&queue);
    count = 1;
    scanf("%d %d", &N, &M);
    for (int j = 0; j < N; j++) {
      scanf("%d", &priority[j]);
      if (j == M)
        enqueue(&queue, priority[j], 1);
      else
        enqueue(&queue, priority[j], 0);
    }
    while (1) {
      if (isEmpty(&queue))
        break;
      else if (!isEmpty(&queue) && compare(&queue)) {
        if (dequeue(&queue)) {
          printf("%d\n", count);
          break;
        }
        count++;
      }
    }
  }

  return 0;
}