#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int asNum(int a, int b, int c) { return (a + b) - c; }

int asString(int a, int b, int c) {
  char aStr[MAX] = "\0";
  char bStr[MAX] = "\0";
  char abStr[MAX] = "\0";
  sprintf(aStr, "%d", a);
  sprintf(bStr, "%d", b);
  sprintf(abStr, "%s", strcat(aStr, bStr));
  return atoi(abStr) - c;
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n%d", asNum(a, b, c), asString(a, b, c));
}