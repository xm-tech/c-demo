// add is a function pointer, which can be easiely used as a function parameter
// func 是 1 指向函数的指针, 这里的参数和返回值都可以是任意结构体，那么就可以像 skynet 一样实现通用的函数回调
typedef int(*func) (int, int);
