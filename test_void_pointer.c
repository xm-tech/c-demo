#include <stdio.h>

int add_(void *a, void *b);

int add_(void *a, void *b) {
	int* a_=a;
	int* b_=b;
	return (int)(*a_ + *b_);
};

int main(){
	int a = 5;
	int b = 6;
	int c = add_(&a, &b);
	printf("c=%d\n", c);
}
