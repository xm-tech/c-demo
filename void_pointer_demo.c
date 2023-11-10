#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add_(void *a, void *b);

int add_(void *a, void *b) {
	int* a_=a;
	int* b_=b;
	return (int)(*a_ + *b_);
};

void swap(void *a, void *b, size_t tsize);

void swap(void *a, void *b, size_t tsize) {
	void * tmp = malloc(tsize);
	if (tmp == NULL) {
		printf("swap fail, malloc fail");
		return;
	}
	// copy a into tmp
	memcpy(tmp, a, tsize);
	// copy b into a
	memcpy(a, b, tsize);
	// copy tmp into b
	memcpy(b, tmp, tsize);
	free(tmp);
}

int main(){
	int a = 5;
	int b = 6;
	int c = add_(&a, &b);
	printf("c=%d\n", c);
}
