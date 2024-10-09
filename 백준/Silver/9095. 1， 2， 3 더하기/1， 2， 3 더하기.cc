#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

void DFS(int target, int sum) {
  if (sum == target) {
    cnt++;
    return;
  } else if (sum > target) // 누계가 타겟을 넘어갈 경우 무한 재귀에 빠지므로
                           // 반드시 예외처리
    return;
  for (int i = 1; i <= 3; i++)
    DFS(target, sum + i);
  return;
}

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    DFS(n, 0);
    printf("%d\n", cnt);
    cnt = 0;
  }
  return 0;
}