#include <stdio.h>

int main() {
  double a, b;
  scanf("%lf %lf", &a, &b);
  printf("%.13f\n", a / b);
  return 0;
}