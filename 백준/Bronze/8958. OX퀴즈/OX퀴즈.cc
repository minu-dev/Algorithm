#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000

int main() {
  char ans[80];
  int T;
  int combo = 0;
  int score = 0;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    scanf("%s", ans);
    int len = strlen(ans);
    for (int j = 0; j < len; j++) {
      if (ans[j] == 'O') {
        score++;
        score += combo;
        combo++;
      } else
        combo = 0;
    }
    printf("%d\n", score);
    score = 0;
    combo = 0;
  }

  return 0;
}