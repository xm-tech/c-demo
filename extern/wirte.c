#include <stdio.h>

extern int count;
void write(){
	// here count comes from main.c
	printf("write in write.c, count=%d\n", count);
}
