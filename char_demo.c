#include <stdio.h>

int main() {
	while (1) {
		char input[50];
		// 从标准输入读取一行字符存储到 input, 若输入长度大于
		// 50，或者遇到行结束符,则继续循环
		fgets(input, 50, stdin);
		/* printf("input=%s\n", input); */
		puts(input);
	}

	/* char *ptr; */
	/* for (int i=0; i < 5; i++) { */
	/* 	*ptr++ = i; */
	/* } */

	/* printf("ptr=%s", ptr); */
	return 0;
}
