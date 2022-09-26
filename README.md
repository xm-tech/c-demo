# c examples

# build

make all

# TODO

- [x] c basic lan
- [x] c struct
- [x] c pointer
- [x] function pointer
- c net op
- c file op
- c db op
- c mq
- c-lua
- c chess demo


# The Course

- [site](https://www.runoob.com/cprogramming/c-tutorial.html)

- [Progress](https://www.runoob.com/cprogramming/c-functions.html)

# tips

> about static

```c

/**
In C, functions are global by default. 

Unlike global functions in C, access to static functions is restricted to the file where they are declared. 
Therefore, when we want to restrict access to functions, we make them static. 
Another reason for making functions static can be reuse of the same function name in other files.

*/
static void f(); // 这里的 static 说明此 f 函数只在当前文件可见

// only visible to this file
static int a = 5; // 这里的 static 说明 a 的值，只初始化 1次， 之后的每次调用都在当前值的基础上变化，即使它被定义在函数的内部
```
