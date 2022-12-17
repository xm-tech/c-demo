c examples
==========

build
-----

```shell
make all
```

The Course
----------

- [site](https://www.runoob.com/cprogramming/c-tutorial.html)

- [Progress](https://www.runoob.com/cprogramming/c-functions.html)

tips
----

> about static

```c

/**
In C, functions are global by default. 

Unlike global functions in C, access to static functions is restricted to the 
file where they are declared. Therefore, when we want to restrict access to 
functions, we make them static. Another reason for making functions static can 
be reuse of the same function name in other files.

*/
static void f(); // 这里的 static 说明此 f 函数只在当前文件可见

// only visible to this file
static int a = 5; // 这里的 static 说明 a 的值，只初始化 1次， 之后的每次调用都在当前值的基础上变化，即使它被定义在函数的内部
// 这里 Q 这个变量是静态的，只能在声明所在的文件被访问，且它的值是会记忆的在每次函数调用间, 所以消息队列这种概念，就很适合声明为 static 的
static struct global_quene * Q=null
```

> funciton pointer

```c
pointer referred to a function
sutiable to be used as a param of a function to implement interface like things

```

> const

....

> inline function

....
