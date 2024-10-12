#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int result[2] = {0, 0};

void DFS(int **arr, int x, int y, int size) {
  bool Color[2] = {true, true};
  // Color[0] -> Zero, Color[1] -> One
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      Color[!arr[i][j]] = false;
    }
  }
  if (Color[0]) {
    result[0]++;
    return;
  } else if (Color[1]) {
    result[1]++;
    return;
  }

  DFS(arr, x, y, size / 2);
  DFS(arr, x, y + size / 2, size / 2);
  DFS(arr, x + size / 2, y, size / 2);
  DFS(arr, x + size / 2, y + size / 2, size / 2);
}

int main() {
  int n;
  int K = 0;
  scanf("%d", &n);
  int **arr = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(sizeof(int) * n);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &arr[i][j]);
  DFS(arr, 0, 0, n);
  printf("%d\n%d\n", result[0], result[1]);
}