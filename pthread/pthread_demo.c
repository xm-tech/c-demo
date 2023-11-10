#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct person {
	char *name;
	int age;
} person;

typedef struct req {
	int cmd;
	void * data;
} req;

typedef struct resp {
	int err_code;
	char *msg;
} resp;

resp *handle(req *r) {
	printf("handle, req.cmd:%d, req.data:%s\n", r->cmd, (char *)r->data);
	resp *res;
	res = malloc(sizeof(resp));
	res->msg = (char *)r->data;
	res->err_code = 200;
	return res;
}

person* create_person(char *name, int age) {
	person *p = malloc(sizeof(person));
	p->name = name;
	p->age = age;
	return p;
}

void *doSth(void *p) {
	resp *res = handle((req *)p);
	pthread_t cur_t = pthread_self();
	printf("doSth,tid:%lu,err_code:%d,msg:%s\n", (unsigned long)cur_t, res->err_code, res->msg);
	return NULL;
}

int main(int argc, char *argv[]) {
	printf("argc:%d\n", argc);
	for (int i=0; i < argc; i++) {
		printf("argv[%d]:%s\n", i, argv[i]);
	}

	char *name = argv[1];
	// char *age = argv[2];
	int age = atoi(argv[2]);
	printf("name:%s,age:%d\n", name, age);
	person *p = create_person(name, age);
	char ret[100];
	sprintf(ret, "create_person succ,name=%s,age=%d", p->name, p->age);
	printf("%s\n", ret);

	printf("before pthread create\n");

	req *data = malloc(sizeof(*data));
	data->cmd = 1000;
	data->data = "yes";
	
	pthread_t tids[2] = {};

	pthread_create(&tids[0], NULL, doSth, data);
	pthread_create(&tids[1], NULL, doSth, data);
	// block until work finished
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	printf("after pthread exec\n");
	return 0;	
}
