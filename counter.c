#include <stdio.h>
static int count = 10;

void work();

int main(){

	while (count-->0) {
		work();
	}

	return 0;
}



void work(void){
	static int c = 5;
	c++;
	printf("count:%d,c:%d \n", count, c);
}
