#include <stdio.h>
#include <stdlib.h>
#define MIN(A, B) (A < B) ? A : B

void sortByParent(int *arr, int index) {
  if (index == 0)
    return;
  if (arr[index] < arr[(index - 1) / 2]) {
    int tmp = arr[index];
    arr[index] = arr[(index - 1) / 2];
    arr[(index - 1) / 2] = tmp;
  }
  sortByParent(arr, (index - 1) / 2);
}

void heapfify(int *arr, int index, int size) {
  int left = 2 * index + 1;
  int right = left + 1;
  int smallest = index;

  if (left <= size && arr[left] < arr[smallest])
    smallest = left;
  if (right <= size && arr[right] < arr[smallest])
    smallest = right;

  if (smallest != index) {
    int tmp = arr[index];
    arr[index] = arr[smallest];
    arr[smallest] = tmp;
    heapfify(arr, smallest, size);
  }
}

void insert(int *arr, int index, int data) {
  arr[index] = data;
  sortByParent(arr, index);
}

int discharge(int *arr, int size) {
  int tmp = arr[0];
  arr[0] = arr[size];
  arr[size] = 0;
  return tmp;
}

int main() {
  int n;
  int size = -1;
  scanf("%d", &n);
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      if (size == -1)
        printf("0\n");
      else {
        printf("%d\n", discharge(arr, size--));
        heapfify(arr, 0, size);
      }
    } else
      insert(arr, ++size, x);
  }
}