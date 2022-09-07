#include <stdio.h>

// 函数声明
int add(int, int);

int main() {
	int a = 3, b = 5;
	int ret = add(a, b);
	printf("ret=%d \n", ret);
	return 0;
}

// 函数实现
int add(int a, int b) {
	return a + b;
}
