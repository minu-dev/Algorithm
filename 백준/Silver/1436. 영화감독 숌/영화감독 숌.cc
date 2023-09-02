#include <stdio.h>
#include <string.h>

int main () {
    int N;
    int cnt = 1;
    int num = 666;
    scanf("%d", &N);
    
    while (N != cnt) {
        num++;
        char toStr[20];
        sprintf(toStr, "%d", num);
        char *ptr = strstr(toStr, "666");
        if (ptr != NULL) cnt++;
    }

    printf("%d\n", num);
}