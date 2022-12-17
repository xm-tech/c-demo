The best practice to code with clang
====================================

place .h and .c in the same directory
-------------------------------------

so that we can emit the path info about .h files in the **#include** directives

always begins the .h file with ifndef FILENAME_H_
-------------------------------------------------

to avoid redundant include errors

use **//** comments anywhere, never **/\* ... \*/**
-------------------------------------------------
