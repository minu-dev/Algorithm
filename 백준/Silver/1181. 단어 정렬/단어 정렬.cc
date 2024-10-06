#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


//비교 수행하는 함수, qsort의 4번째 인자
int compare(const void* arg1, const void* arg2) 
{   //길이순 정렬
	if (strlen((const char*)arg1) > strlen((const char*)arg2)) return 1;
	else if (strlen((const char*)arg1) < strlen((const char*)arg2)) return -1;
	//길이 같으면 사전순
	else return strcmp((char*)arg1, (char*)arg2);
} 
int main(void)
{    
	int size, length = 51;
	char arr[20000][51] = { 0 };
	scanf("%d", &size);

	for (int i = 0; i < size; i++)      
		scanf("%s", arr[i]);

	//정렬
	qsort(arr, size, sizeof(arr[0]), compare);
	
	//정렬 후 같은 문자열은 생략하고 출력
	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i], arr[i+1]) != 0 || i == size - 1)
			printf("%s\n", arr[i]);
	}
	return 0;
}