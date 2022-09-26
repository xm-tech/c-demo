#include "test_function_pointer.h"
#include <stdio.h>

int add_(int a, int b){
	int c = a + b;
	printf("add_(%d,%d)=%d\n", a, b, c);
	return c;	
};

int sub_(int a, int b) {
	int c = a - b;
	printf("sub_(%d,%d)=%d\n", a, b, c);
	return c;
};

// static means this function can only be accessed from the current file
static int call_func(func p, int a, int b) {
	printf("call_func: a=%d,b=%d\n", a, b);
	return p(a, b);
}

int main(){
	func f;
	f = &add_;
	int r = f(3, 5);
	printf("r=%d\n", r);

	f = &sub_;
	r = f(3, 5);
	printf("r=%d\n", r);

	// skynet 的函数调用好多都是这么做的
	int v = call_func(f, 11, 3);
	printf("v=%d\n", v);
}

