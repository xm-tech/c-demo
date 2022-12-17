#include <stdio.h>
#include <time.h>

static inline unsigned long now() { return (unsigned long)time(NULL); }

static inline int add(int a, int b) {
	printf("call add(%d,%d)\n", a, b);
	return a + b;
}

static void with_inline_func() {
	unsigned long begin = now();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			add(i, j);
		}
	}
	unsigned long end = now();
	printf("with_inline_func,elapsed:%lu\n", (end - begin));
}

static int add2(int a, int b) {
	printf("call add2(%d,%d)\n", a, b);
	return a + b;
}

static void with_plain_func() {
	unsigned long begin = now();
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			add2(i, j);
		}
	}
	unsigned long end = now();
	printf("with_plain_func,elapsed:%lu\n", (end - begin));
}

int main() {
	printf("now=%lu\n", now());
	with_inline_func();
	with_plain_func();
	return 0;
}
