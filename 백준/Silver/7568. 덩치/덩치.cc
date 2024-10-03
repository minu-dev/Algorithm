#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct big {
  int x;
  int y;
  int rank;
} big;

int main() {
  int n;
  scanf("%d", &n);
  big *arr = (big *)malloc(sizeof(big) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i].x, &arr[i].y);
    arr[i].rank = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i].x < arr[j].x && arr[i].y < arr[j].y)
        arr[i].rank++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i].rank);
  }
  printf("\n");
  return 0;
}