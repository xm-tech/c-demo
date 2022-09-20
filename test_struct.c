#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#define MAX_CLASS_STU_NUM 3

typedef struct {
	char name[10];
	int age;
	int sex;
} person;

// 学生
typedef struct {
	person per;
	double score; 
} student;

// 老师，use module: typedef primitive-type/userdefined-type
typedef struct{
	person per;
} teacher;

// 班级
typedef struct {
	String name; // 班级名，same as char *name
	student *students[MAX_CLASS_STU_NUM];
	int stu_num;
} clazz;

void display_student(student *stu);

// 某个学生加入某个班级
void join_class(clazz *cl, student *stu);

int main(int argc, char **argv){
	student maxm = {{"maxm", 37, 0}, 79};
	display_student(&maxm);

	student lfj = {{"lfj", 37, 1}, 90};
	display_student(&lfj);

	student wsr = {{"wsr", 35, 1}, 93};
	display_student(&wsr);

	student tq = {{"tq", 35, 1}, 98};
	display_student(&tq);

	clazz *classA = malloc(sizeof(clazz));
	classA->stu_num = 0;
	classA->name = "高三1班";

	join_class(classA, &maxm);
	join_class(classA, &lfj);
	join_class(classA, &wsr);
	join_class(classA, &tq);
}

void display_student(student *stu) {
	printf("student{name:\"%s\", age:%d, sex:%d, score:%.2f} \n", stu->per.name, stu->per.age, stu->per.sex, stu->score);
}

void join_class(clazz *cl, student *stu) {
	if (cl->stu_num >= MAX_CLASS_STU_NUM) {
		printf("%s join_class {%s} fail, max student num: %d \n", stu->per.name, cl->name, MAX_CLASS_STU_NUM);
		return;
	}
	cl->students[cl->stu_num++] = stu;
	printf("{%s} joined {%s}, stu_num=%d \n", stu->per.name, cl->name, cl->stu_num);
}



