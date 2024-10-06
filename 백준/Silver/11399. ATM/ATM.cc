#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct People {
  int idx;
  int time;
} People;

int static compare(const void *first, const void *second) {
  People *a = (People *)first;
  People *b = (People *)second;
  if (a->time > b->time)
    return 1;
  else if (a->time < b->time)
    return -1;
  else
    return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  People *people = (People *)malloc(sizeof(People) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &people[i].time);
    people[i].idx = i + 1;
  }
  qsort(people, n, sizeof(People), compare);
  int sum = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j >= 0; j--)
      sum += people[j].time;
  printf("%d\n", sum);
  return 0;
}