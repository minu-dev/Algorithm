#include <stdio.h>
#define MAX 100

int main() {
  long int X;
  int N;
  long int price[MAX] = {
      0,
  };
  int count[MAX] = {
      0,
  };
  int sum = 0;

  scanf("%ld %d", &X, &N);
  for (int i = 0; i < N; i++) {
    scanf("%ld %d", &price[i], &count[i]);
  }
  for (int i = 0; i < N; i++) {
    sum += price[i] * count[i];
  }
  if (sum == X)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}