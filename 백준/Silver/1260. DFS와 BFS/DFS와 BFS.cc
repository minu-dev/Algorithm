#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAX 1001

typedef struct Queue {
  int front;
  int rear;
  int data[QUEUE_MAX];
} Queue;

void initQueue(Queue *q) {
  q->front = q->rear = -1;
  for (int i = 0; i <= QUEUE_MAX; i++)
    q->data[i] = 0;
}

int isEmpty(Queue *q) { return q->front == q->rear; }

int isFull(Queue *q) { return q->rear == QUEUE_MAX - 1; }

void enqueue(Queue *q, int data) {
  if (isFull(q))
    exit(0);
  q->data[++q->rear] = data;
  return;
}

int dequeue(Queue *q) {
  if (isEmpty(q))
    exit(0);
  return q->data[++q->front];
}

void DFS(int *visited, int **edge, int start, int size) {
  visited[start] = 0;
  printf("%d ", start);
  for (int i = 1; i <= size; i++) {
    if (edge[start][i] && visited[i]) {
      DFS(visited, edge, i, size);
    }
  }
}

void BFS(int *visited, int **edge, int cursor, int size) {
  Queue q;
  initQueue(&q);
  visited[cursor] = 1;
  printf("%d ", cursor);
  enqueue(&q, cursor);
  while (!isEmpty(&q)) {
    cursor = dequeue(&q);
    for (int i = 1; i <= size; i++) {
      if (edge[cursor][i] && !visited[i]) {
        visited[i] = 1;
        printf("%d ", i);
        enqueue(&q, i);
      }
    }
  }
}

int main() {
  int n, m, v;
  scanf("%d %d %d", &n, &m, &v);
  int *vertex = (int *)malloc(sizeof(int) * (n + 1));
  int **edge = (int **)malloc(sizeof(int *) * (n + 1));
  for (int i = 0; i < n + 1; i++)
    edge[i] = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    vertex[x] = vertex[y] = 1;
    edge[x][y] = edge[y][x] = 1;
  }
  int *visited = (int *)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n + 1; i++) {
    visited[i] = vertex[i];
  }
  DFS(visited, edge, v, n);
  printf("\n");
  BFS(visited, edge, v, n);
  printf("\n");

  free(vertex);
  for (int i = 0; i < n + 1; i++) {
    free(edge[i]);
  }
  free(edge);
  return 0;
}