#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *solve(int **ground, int blocks, int min, int max, int n, int m) {
  int minTime = INT_MAX, height = INT_MIN;
  int remain, time;
  int cursor = max;
  while (cursor >= min) {
    time = 0;
    remain = blocks;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ground[i][j] > cursor) {
          time += (ground[i][j] - cursor) * 2;
          remain += ground[i][j] - cursor;
        } else if (ground[i][j] < cursor) {
          time += cursor - ground[i][j];
          remain -= cursor - ground[i][j];
        }
      }
    }
    if (remain >= 0) {
      if (time < minTime) {
        minTime = time;
        height = cursor;
      } else if (time == minTime) {
        if (cursor > height)
          height = cursor;
      }
    }
    cursor--;
  }
  int *arr = (int *)malloc(sizeof(int) * 2);
  arr[0] = minTime;
  arr[1] = height;
  return arr;
}

int main() {
  int n, m, b;
  int max = INT_MIN;
  int min = INT_MAX;
  scanf("%d %d %d", &n, &m, &b);
  int **ground = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    ground[i] = (int *)malloc(sizeof(int) * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &ground[i][j]);
      if (ground[i][j] > max)
        max = ground[i][j];
      if (ground[i][j] < min)
        min = ground[i][j];
    }
  }
  int *arr = solve(ground, b, min, max, n, m);
  printf("%d %d\n", arr[0], arr[1]);
  return 0;
}