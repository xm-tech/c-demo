#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

#define MAX_CLASS_STU_NUM 3

struct student {
	char name[10];
	int age;
	int sex;
	double money; 
};

// 班级
struct clazz {
	String name; // same as char *name
	struct student students[MAX_CLASS_STU_NUM];
	int stu_num;
};


void display_student(struct student stu);

// 某个学生加入某个班级
void join_class(struct clazz *cl, struct student stu);

int main(int argc, char **argv){
	struct student maxm = {"maxm", 37, 0, 1000000.33};
	display_student(maxm);
	struct student lfj = {"lfj", 37, 1, 1000000.33};
	display_student(lfj);
	struct student wsr = {"wsr", 35, 1, 1000000.33};
	display_student(wsr);
	struct student tq = {"tq", 35, 1, 1000000.33};
	display_student(tq);

	struct clazz *classA = malloc(sizeof(struct clazz));
	classA->stu_num = 0;
	classA->name = "高三1班";
	join_class(classA, maxm);
	join_class(classA, lfj);
	join_class(classA, wsr);
	join_class(classA, tq);
}

void display_student(struct student stu) {
	printf("student{name:\"%s\", age:%d, sex:%d, money:%.2f}\n", stu.name, stu.age, stu.sex, stu.money);
}

void join_class(struct clazz *cl, struct student stu) {
	if (cl->stu_num >= MAX_CLASS_STU_NUM) {
		printf("%s join_class %s fail, max student num!!\n", stu.name, cl->name);
		return;
	}
	cl->students[cl->stu_num++] = stu;
	printf("stud:{%s} joined, stu_num=%d\n", stu.name, cl->stu_num);
}



