#include <stdio.h>
#include <string.h>

int main() {
  int T, R;
  char S[21];
  char newS[] = "";

  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d %s", &R, S);
    for (int k = 0; k < strlen(S); k++)
      for (int j = 0; j < R; j++) {
        printf("%c", S[k]);
      }
    printf("\n");
  }
}