#include <stdio.h>

#ifndef __ADLIST_H__
#define __ADLIST_H__

typedef struct node {
	struct node *prev;
	struct node *next;
	void *val;
} node_t;

typedef struct iter {
	node_t *next;
	int direction;
} iter_t;

typedef struct list {
	node_t *head;
	node_t *tail;
	void (*free)(struct list *l_ptr);
	unsigned long len;
} list_t;

#endif
