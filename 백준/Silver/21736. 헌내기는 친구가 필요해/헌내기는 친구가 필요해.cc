#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findIndex(char *str, char target) {
  char *ptr = strchr(str, target);
  if (ptr != NULL)
    return ptr - str;
  else
    return -1;
}

int cnt = 0;
void DFS(char **matrix, int **visited, int x, int y, int n, int m) {
  visited[x][y] = 1;
  if (matrix[x][y] == 'P')
    cnt++;
  else if (matrix[x][y] == 'X')
    return;

  int left = x - 1, right = x + 1, up = y + 1, down = y - 1;

  if (left >= 0 && !visited[left][y])
    DFS(matrix, visited, left, y, n, m);

  if (right < n && !visited[right][y])
    DFS(matrix, visited, right, y, n, m);

  if (up < m && !visited[x][up])
    DFS(matrix, visited, x, up, n, m);

  if (down >= 0 && !visited[x][down])
    DFS(matrix, visited, x, down, n, m);

  return;
}

int main() {
  int n, m;
  int start[2];

  scanf("%d %d", &n, &m);

  char **matrix = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++)
    matrix[i] = (char *)malloc(sizeof(char) * (m + 1));

  int **visited = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    visited[i] = (int *)malloc(sizeof(int) * m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      visited[i][j] = 0;

  for (int i = 0; i < n; i++) {
    scanf("%s", matrix[i]);
    int idx = findIndex(matrix[i], 'I');
    if (idx != -1) {
      start[0] = i;
      start[1] = idx;
    }
  }

  DFS(matrix, visited, start[0], start[1], n, m);
  if (cnt == 0)
    printf("TT\n");
  else
    printf("%d\n", cnt);

  for (int i = 0; i < n; i++) {
    matrix[i] = NULL;
    visited[i] = NULL;
    free(matrix[i]);
    free(visited[i]);
  }
  free(matrix);
  free(visited);
  return 0;
}