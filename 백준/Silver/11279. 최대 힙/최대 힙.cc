#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void heapfify(int *heap, int size, int start) {
  int max = start;
  int left = 2 * start + 1;
  int right = left + 1;

  if (left <= size && heap[max] < heap[left])
    max = left;
  if (right <= size &&
      heap[max] < heap[right]) // heap[start] 가 아닌 heap[max] 와 비교해야함
    max = right;

  if (max != start) {
    int tmp = heap[start];
    heap[start] = heap[max];
    heap[max] = tmp;
    heapfify(heap, size, max);
  }
}

void insert(int *heap, int index, int data) {
  heap[index] = data;
  if (index != 0) {
    while (heap[index] > heap[(index - 1) / 2]) {
      int tmp = heap[index];
      heap[index] = heap[(index - 1) / 2];
      heap[(index - 1) / 2] = tmp;
      index = (index - 1) / 2;
    }
  }
}

int eliminate(int *heap, int size) {
  int tmp = heap[0];
  heap[0] = heap[size];
  heap[size] = -1;
  heapfify(heap, size, 0);
  return tmp;
}

int main() {
  int n;
  int size = 0;
  scanf("%d", &n);
  int *heap = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    heap[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      if (size == 0)
        printf("%d\n", 0);
      else {
        printf("%d\n", eliminate(heap, --size));
      }
    } else {
      insert(heap, size++, x);
    }
  }
}
