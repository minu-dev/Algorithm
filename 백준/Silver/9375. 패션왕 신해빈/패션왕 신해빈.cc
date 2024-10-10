#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 21

int typeCount = 0;

typedef struct Clothes {
  int count;
  char type[STRING_LENGTH];
} Clothes;

void initClothes(Clothes *clothes) {
  clothes->count = 0;
  sprintf(clothes->type, "%s", "\0");
  return;
}

void typeSearch(Clothes *clothes, char *type) {
  // 순차탐색
  for (int i = 0; i < typeCount; i++) {
    if (strcmp(clothes[i].type, type) == 0) {
      clothes[i].count++;
      return;
    }
  }
  clothes[typeCount].count++;
  sprintf(clothes[typeCount].type, "%s", type);
  typeCount++;
  return;
}

int Combination(Clothes *clothes, int cursor) {
  if (cursor == typeCount)
    return 1;
  int currentCount = clothes[cursor].count;
  // 예를 들어 같은 종류의 옷이 두 벌 있다면
  // 나올 수 있는 경우의 수는 (2C1 + 2C0) = 3
  // 이는 n이 어떤 값이든 동일함.
  // 따라서 (currentCount + 1) * 에 커서를 옮겨 재귀적으로 같은 연산 수행함.
  return (currentCount + 1) * Combination(clothes, cursor + 1);
}

int main() {
  Clothes clothes[30];
  for (int i = 0; i < 30; i++)
    initClothes(&clothes[i]);
  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      char tmpName[STRING_LENGTH];
      char tmpType[STRING_LENGTH];
      scanf("%s %s", tmpName, tmpType);
      typeSearch(clothes, tmpType);
    }
    // 모두 고르지 않은 경우, 즉 알몸인 경우를 빼줘야 하므로 -1
    printf("%d\n", Combination(clothes, 0) - 1);
    // 구조체 비워주기
    for (int i = 0; i < 30; i++)
      initClothes(&clothes[i]);
    typeCount = 0;
  }
  return 0;
}