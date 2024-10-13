#include <stdio.h>
#include <stdlib.h>

void DFS(int *vertex, int **edge, int start, int size) {
  vertex[start] = 0;
  for (int i = 1; i < size; i++) {
    if (edge[start][i] && vertex[i])
      DFS(vertex, edge, i, size);
  }
}

int main() {
  int n, m;
  int cnt = 0;
  scanf("%d %d", &n, &m);
  n += 1;
  int *vertex = (int *)malloc(sizeof(int) * n);
  int **edge = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    edge[i] = (int *)malloc(sizeof(int) * n);
  for (int i = 1; i < n; i++)
    vertex[i] = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    edge[x][y] = edge[y][x] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (vertex[i]) {
      DFS(vertex, edge, i, n);
      cnt++;
    }
  }
  printf("%d\n", cnt);
}