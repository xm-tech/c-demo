#include <stdio.h>

extern int count;
void write(){
	// the count here comes from main.c
	printf("write in write.c, count=%d\n", count);
}
