#include <stdio.h>

int main(){
	int arr[9];

	for (int i=0; i < 9; i++) {
		arr[i]=i*10;
	}
	
	for (int i=0; i < 9; i++) {
		printf("arr[%d] = %d \n", i, arr[i]);
	}
}
