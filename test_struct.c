#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CLASS_STU_NUM = 3;

struct Student {
	char name[10];
	int age;
	int sex;
	double money; 
};

// 班级
struct Class {
	char *name;
	struct Student students[MAX_CLASS_STU_NUM];
	int stu_num;
};


void display_student(struct Student stu);

// 某个学生加入某个班级
void join_class(struct Class *cl, struct Student stu);

int main(int argc, char **argv){
	struct Student maxm = {"maxm", 37, 0, 1000000.33};
	display_student(maxm);
	struct Student lfj = {"lfj", 37, 1, 1000000.33};
	display_student(maxm);
	struct Student wsr = {"wsr", 35, 1, 1000000.33};
	display_student(maxm);
	struct Student tq = {"tq", 35, 1, 1000000.33};
	display_student(tq);
	
	struct Class *classA = malloc(sizeof(struct Class));
	classA->stu_num = 0;
	classA->name = "高三1班";
	join_class(classA, maxm);
	join_class(classA, lfj);
	join_class(classA, wsr);
	join_class(classA, tq);
}

void display_student(struct Student stu) {
	printf("Student{name:\"%s\", age:%d, sex:%d, money:%lf}\n", stu.name, stu.age, stu.sex, stu.money);
}

void join_class(struct Class *cl, struct Student stu) {
	if (cl->stu_num >= MAX_CLASS_STU_NUM) {
		printf("%s join_class %s fail, max student num!!\n", stu.name, cl->name);
		return;
	}
	cl->students[cl->stu_num++] = stu;
	printf("stud:{%s} joined, stu_num=%d\n", stu.name, cl->stu_num);
}



