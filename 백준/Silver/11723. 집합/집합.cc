#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 3000000

int static Compare(const void *first, const void *second) {
  if (*(char *)first > *(char *)second)
    return 1;
  else if (*(char *)first < *(char *)second)
    return -1;
  else
    return 0;
}

int BinarySearch(char *arr, int size, char target) {
  int low, high, mid;
  low = 0;
  high = size - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (target == arr[mid]) {
      return mid;
    } else if (target < arr[mid])
      high = mid - 1;
    else if (target > arr[mid])
      low = mid + 1;
  }
  return -1;
}

int Add(char *arr, int size, char value) {
  if (BinarySearch(arr, size, value) == -1) {
    arr[size] = value;
    qsort(arr, size + 1, sizeof(char), Compare);
    return 1; // 성공했으면 사이즈 값 올리기 위해
  } else
    return 0; // 실패했으면 사이즈 값 변동 없음
}

int Remove(char *arr, int size, char value) {
  int idx = BinarySearch(arr, size, value);
  if (idx != -1) {
    arr[idx] = CHAR_MAX;
    qsort(arr, size, sizeof(char), Compare);
    return -1; // 성공했으면 사이즈 값 내리기 위해
  } else
    return 0; // 실패했으면 사이즈 값 변동 없음
}

int Check(char *arr, int size, char value) {
  if (BinarySearch(arr, size, value) != -1)
    return 1;
  else
    return 0;
}

int Toggle(char *arr, int size, char value) {
  int idx = BinarySearch(arr, size, value);
  if (idx != -1) {
    arr[idx] = CHAR_MAX;
    qsort(arr, size, sizeof(char), Compare);
    return -1; // 있을 경우 삭제
  } else {
    arr[size] = value;
    qsort(arr, size + 1, sizeof(char), Compare);
    return 1; // 없을 경우 추가
  }
}

int all(char *arr, int size) {
  for (int i = 0; i < 20; i++) {
    arr[i] = i + 1;
  }
  return 20;
}

int main() {
  char arr[MAX_SIZE] = {
      CHAR_MAX,
  };
  int m, arraySize = 0, data;
  char command[20];
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", command);
    if (strcmp(command, "add") == 0) {
      scanf("%d", &data);
      arraySize += Add(arr, arraySize, data);
    } else if (strcmp(command, "remove") == 0) {
      scanf("%d", &data);
      arraySize += Remove(arr, arraySize, data);
    } else if (strcmp(command, "check") == 0) {
      scanf("%d", &data);
      printf("%d\n", Check(arr, arraySize, data));
    } else if (strcmp(command, "toggle") == 0) {
      scanf("%d", &data);
      arraySize += Toggle(arr, arraySize, data);
    } else if (strcmp(command, "all") == 0) {
      arraySize = all(arr, arraySize);
    } else if (strcmp(command, "empty") == 0) {
      arraySize = 0;
    }
  }
  return 0;
}