#include <stdio.h>

int arr[52][52] = {
    0,
};
int cnt = 0;

void init() {
  for (int i = 0; i < 52; i++)
    for (int j = 0; j < 52; j++)
      arr[i][j] = 0;
  cnt = 0;
}

void DFS(int x, int y) {
  arr[x][y] = 0;
  // else if 사용 시 한 칸 만 붙어있는게 아닌 경우
  // 예를 들어, 왼쪽에도 1이 있고, 오른쪽에도 1이 있는 경우
  // 이러한 케이스를 포함하지 못함
  // 따라서 모두 if로 사용
  if (arr[x + 1][y])
    DFS(x + 1, y);
  if (arr[x - 1][y])
    DFS(x - 1, y);
  if (arr[x][y + 1])
    DFS(x, y + 1);
  if (arr[x][y - 1])
    DFS(x, y - 1);
  return;
}

int main() {
  int t, m, n, k, x, y;
  scanf("%d", &t);
  for (int a = 0; a < t; a++) {
    init();
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
      scanf("%d %d", &x, &y);
      arr[x + 1][y + 1] = 1;
    }
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        if (arr[i][j]) {
          DFS(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
