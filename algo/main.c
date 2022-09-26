#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "linkedlist.h"

int main(int argc, char **argv) {
	node_t * head = malloc(sizeof(node_t));	
	head->val = 11;
	head->next = (node_t *)malloc(sizeof(node_t));
	head->next->val = 111;
	head->next->next = NULL;
	// FIXME why here fail !!!
	display(head);
}
