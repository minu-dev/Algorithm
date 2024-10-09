#include <stdio.h>
#include <stdlib.h>
#define MAX_GRAPH 101

int graph[MAX_GRAPH][MAX_GRAPH] = {
    0,
};
int visited[MAX_GRAPH] = {
    0,
};
int cnt = 0;

void DFS(int cursor, int size) {
  int i = 1;
  visited[cursor] = 1;
  for (; i <= size; i++) {
    if (graph[cursor][i] == 1 && visited[i] == 0) {
      cnt++;
      DFS(i, size);
    }
  }
  return;
}

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  for (int i = 0; i < l; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    graph[x][y] = graph[y][x] = 1;
  }
  DFS(1, n);
  printf("%d\n", cnt);
  return 0;
}
