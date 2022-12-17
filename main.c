#include <stdio.h>

// 此处 extern 标明方法的定义在另外的源文件中
extern int add(int, int);
extern int incr(int);

int main(int argc, char **argv){
	// test add func
	int a = 3, b = 5;
	int ret = add(a, b);
	printf("add(%d,%d)=%d \n", a, b, ret);

	// test incr func
	int r = incr(ret);
	printf("incr(%d)=%d \n", ret, r);
	return 0;
}
