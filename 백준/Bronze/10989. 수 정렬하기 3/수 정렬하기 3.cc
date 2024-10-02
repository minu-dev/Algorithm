#include <stdio.h>

// qsort 사용 시 메모리 초과 발생
//자료형을 int → short로 바꾸어도 마찬가지
//메모리 8MB의 제한이 있으므로, 천 만 개의 int를 생성하면 안됨
//입력되는 수의 조건이 10000 이하의 자연수 이므로,
// 10001 크기의 배열을 생성한 뒤, 입력되는 값을 인덱스로 하여
//어떤 수가 입력될 때 마다, 그 수를 인덱스로 취하여 값을 1씩 증가
//검색해보니, 이러한 정렬을 '카운팅 정렬'이라고 함

int main() {
  int idx[10001] = {
      0,
  };
  int n, num;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    idx[num]++;
  }
  for (int i = 1; i < 10001; i++) {
    if (idx[i] != 0)
      for (int j = 0; j < idx[i]; j++) {
        printf("%d\n", i);
      }
  }
}