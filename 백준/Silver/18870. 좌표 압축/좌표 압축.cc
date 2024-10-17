#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
  int value;
  int order;
  int compress_value;
} Coordinate;

int static compareByValue(const void *first, const void *second) {
  Coordinate *a = (Coordinate *)first;
  Coordinate *b = (Coordinate *)second;
  if (a->value > b->value)
    return 1;
  else if (a->value < b->value)
    return -1;
  else
    return 0;
}

int static compareByOrder(const void *first, const void *second) {
  Coordinate *a = (Coordinate *)first;
  Coordinate *b = (Coordinate *)second;
  if (a->order > b->order)
    return 1;
  else if (a->order < b->order)
    return -1;
  else
    return 0;
}

void compress(Coordinate *coordinate, int n) {
  int rem, cnt = 0;
  coordinate[0].compress_value = cnt;
  rem = coordinate[0].value;
  for (int i = 1; i < n; i++) {
    if (rem == coordinate[i].value)
      coordinate[i].compress_value = cnt;
    else {
      coordinate[i].compress_value = ++cnt;
      rem = coordinate[i].value;
    }
  }
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  Coordinate *coordinate = (Coordinate *)malloc(sizeof(Coordinate) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &coordinate[i].value);
    coordinate[i].order = i;
    coordinate[i].compress_value = -1;
  }
  qsort(coordinate, n, sizeof(Coordinate), compareByValue);
  compress(coordinate, n);
  qsort(coordinate, n, sizeof(Coordinate), compareByOrder);
  for (int i = 0; i < n; i++)
    printf("%d ", coordinate[i].compress_value);
  printf("\n");
}