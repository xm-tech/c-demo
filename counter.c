#include <stdio.h> // 引入标准库

#include "math-me.h"


static int count = 10;

void work();

int main(){

	while (count-->0) {
		work();
	}

	return 0;
}



void work(int argc, int *argv){
	static int c = 5;
	c = incr(c);
	/* c++; */

	printf("count:%d,c:%d \n", count, c);
}
