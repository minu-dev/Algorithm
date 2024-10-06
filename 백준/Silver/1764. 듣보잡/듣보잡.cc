#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Names {
  char name[21];
} Names;

int static compare(const void *first, const void *second) {
  Names *a = (Names *)first;
  Names *b = (Names *)second;
  if (strcmp(a->name, b->name) > 0)
    return 1;
  else if (strcmp(a->name, b->name) < 0)
    return -1;
  else
    return 0;
}

int binarySearch(Names *names, int size, char *target) {
  int low, mid, high;
  low = 0;
  high = size - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (strcmp(names[mid].name, target) == 0)
      return 1;
    else if (strcmp(names[mid].name, target) > 0)
      high = mid - 1;
    else if (strcmp(names[mid].name, target) < 0)
      low = mid + 1;
  }
  return 0;
}

int main() {
  int n, m;
  int cnt = 0;
  scanf("%d %d", &n, &m);
  Names *names = (Names *)malloc(sizeof(Names) * n);
  Names *redundance = (Names *)malloc(sizeof(Names) * m);
  for (int i = 0; i < n; i++)
    scanf("%s", names[i].name);
  qsort(names, n, sizeof(Names), compare);
  for (int i = 0; i < m; i++) {
    char tmp[21];
    scanf("%s", tmp);
    if (binarySearch(names, n, tmp)) {
      sprintf(redundance[cnt++].name, "%s", tmp);
    }
  }
  printf("%d\n", cnt);
  qsort(redundance, cnt, sizeof(Names), compare);
  for (int i = 0; i < cnt; i++) {
    printf("%s\n", redundance[i].name);
  }
  return 0;
}