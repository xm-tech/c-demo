#include <stdio.h>
#include <time.h>

/**
 * inline
 * 标识此函数为内联函数，对于短小精悍，调用频繁，调用开销大的函数可以声明为内联函数,
 * 编译器在编译过程遇到内联函数，像宏一样,将内联函数在调用处展开，
 * 因此会减少函数调用的开销:
 * 因为会直接执行展开的代码，不再保存和恢复普通函数调用的现场等，
 * 内联函数缺点是会增大程序的体积
 * 展开条件：gcc 编译优化等级开到 -O2 以上
 *
 * 内连函数的定义与使用该函数的代码需在同一文件中
 * 内连函数无法在调试器中显示（因为展开了)
 *
 * 内联函数使用习惯 ：1: 用 static 修饰, 2: 定义在头文件中
 */
static inline unsigned long now() { return (unsigned long)time(NULL); }

static inline int add1(int a, int b) {
	printf("call add1(%d,%d)\n", a, b);
	return a + b;
}

static void with_inline_func() {
	// register: 建议编译器在为变量分配存储空间时，将这个变量放到寄存器
	register unsigned long begin = now();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			add1(i, j);
		}
	}
	register unsigned long end = now();
	printf("with_inline_func,elapsed:%lu\n", (end - begin));
}

static int add2(int a, int b) {
	printf("call add2(%d,%d)\n", a, b);
	return a + b;
}

static void with_plain_func() {
	register unsigned long begin = now();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			add2(i, j);
		}
	}
	register unsigned long end = now();
	printf("with_plain_func,elapsed:%lu\n", (end - begin));
}

int main() {
	printf("now=%lu\n", now());
	with_inline_func();
	with_plain_func();
	return 0;
}
