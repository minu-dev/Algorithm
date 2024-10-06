#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Keychain {
  char domain[21];
  char pwd[21];
} Keychain;

int static compare(const void *first, const void *second) {
  Keychain *a = (Keychain *)first;
  Keychain *b = (Keychain *)second;
  if (strcmp(a->domain, b->domain) > 0)
    return 1;
  else if (strcmp(a->domain, b->domain) < 0)
    return -1;
  else
    return 0;
}

char *binarySearch(Keychain *keychain, int size, char *target) {
  int low, high, mid;
  low = 0;
  high = size - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (strcmp(keychain[mid].domain, target) == 0)
      return keychain[mid].pwd;
    else if (strcmp(keychain[mid].domain, target) > 0)
      high = mid - 1;
    else if (strcmp(keychain[mid].domain, target) < 0)
      low = mid + 1;
  }
  return "";
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Keychain *keychain = (Keychain *)malloc(sizeof(Keychain) * n);
  for (int i = 0; i < n; i++)
    scanf("%s %s", keychain[i].domain, keychain[i].pwd);
  qsort(keychain, n, sizeof(Keychain), compare);
  for (int i = 0; i < m; i++) {
    char tmp[21];
    scanf("%s", tmp);
    printf("%s\n", binarySearch(keychain, n, tmp));
  }
  return 0;
}