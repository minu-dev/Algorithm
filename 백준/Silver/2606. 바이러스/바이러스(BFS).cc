#include <stdio.h>
#include <stdlib.h>
#define MAX_GRAPH 101

//// QUEUE ////

typedef struct Queue {
  int data[MAX_GRAPH];
  int front, rear;
} Queue;

void initQueue(Queue *q) {
  q->front = q->rear = -1;
  for (int i = 0; i < MAX_GRAPH; i++)
    q->data[i] = 0;
}

int isEmpty(Queue *q) { return q->front == q->rear; }

int isFull(Queue *q) { return q->rear == MAX_GRAPH - 1; }

void error(char *msg) {
  fprintf(stderr, "%s", msg);
  exit(1);
}

void enqueue(Queue *q, int data) {
  if (isFull(q))
    error("Overflow\n");
  q->rear++;
  q->data[q->rear] = data;
}

int dequeue(Queue *q) {
  if (isEmpty(q))
    error("Underflow\n");
  q->front++;
  return q->data[q->front];
}

//// BFS ////

int graph[MAX_GRAPH][MAX_GRAPH] = {
    0,
};
int visited[MAX_GRAPH] = {
    0,
};
int cnt = 0;

void edge(int start, int end, int size) {
  if (start > size || end > size)
    error("Edge Index Error\n");
  graph[start][end] = graph[end][start] = 1;
  return;
}

void BFS(int cursor, int size) {
  Queue q;
  initQueue(&q);
  visited[cursor] = 1;
  enqueue(&q, cursor);
  while (!isEmpty(&q)) {
    cursor = dequeue(&q);
    for (int i = 1; i <= size; i++) {
      if (graph[cursor][i] && !visited[i]) {
        visited[i] = 1;
        cnt++;
        enqueue(&q, i);
      }
    }
  }
}

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  for (int i = 0; i < l; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    edge(x, y, n);
  }
  BFS(1, n);
  printf("%d\n", cnt);
  return 0;
}
