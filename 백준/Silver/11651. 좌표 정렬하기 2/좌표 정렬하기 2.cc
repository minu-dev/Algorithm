#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct coordinate {
  int x;
  int y;
} coordinate;

int static compare(const void *first, const void *second) {
  if ((*(const coordinate *)first).y > (*(const coordinate *)second).y) {
    return 1;
  } else if ((*(const coordinate *)first).y < (*(const coordinate *)second).y) {
    return -1;
  } else {
    if ((*(const coordinate *)first).x > (*(const coordinate *)second).x) {
      return 1;
    } else if ((*(const coordinate *)first).x <
               (*(const coordinate *)second).x) {
      return -1;
    } else
      return 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  coordinate *arr = (coordinate *)malloc(sizeof(coordinate) * n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &arr[i].x, &arr[i].y);
  qsort(arr, n, sizeof(coordinate), compare);
  for (int i = 0; i < n; i++)
    printf("%d %d\n", arr[i].x, arr[i].y);
  return 0;
}