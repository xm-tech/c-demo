#include <stdlib.h>
#include "adlist.h"

void free_list_mem(list_t *l_ptr) {
}

int main() {

	list_t *l = malloc(sizeof(*l));
	if (l == NULL) {
		return 1;
	}

	node_t *head = malloc(sizeof(*head));
	head->val = (int*)1;
	l->head = head;
	l->tail = NULL;
	l->len = 0;
	l->free = free_list_mem;


	l->free(l);
}


