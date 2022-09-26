#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef union {
	int i;
	float f;
	short s;
	char *ss;
} data_u_t;

int main(){
	data_u_t* d_u = malloc(sizeof(data_u_t));
	d_u->f = 3.3;
	printf("d_u.f=%.2f\n", d_u->f);

	assert(d_u->i = 33);
	printf("d_u.i=%d\n", d_u->i);
	printf("d_u.f=%.2f\n", d_u->f);
}
