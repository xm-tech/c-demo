#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

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

void *doSth(void *p) {
	resp *res = handle((req *)p);
	pthread_t cur_t = pthread_self();
	printf("doSth,tid:%lu,err_code:%d,msg:%s\n", (unsigned long)cur_t, res->err_code, res->msg);
	return NULL;
}

int main() {
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
