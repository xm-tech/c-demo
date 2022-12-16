#include <stdio.h>

extern int count;
void print_count(){
	// the count here comes from main.c
	printf("write in write.c, count=%d\n", count);
}
