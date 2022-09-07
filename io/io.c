#include <stdio.h>

int main(){
	int num;
	printf("plz input a num\n");
	scanf("%d", &num);

	(num%2==0)?printf("偶数"):printf("奇数");
	printf("\n");
}
