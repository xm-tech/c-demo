#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// iterate a linkedlist
void display(node_t * head) {
	node_t * current = head;
	while (current != NULL) {
		printf("current.val=%d\n", current->val);
		current = current->next;
	}
}

// FIXME why only ** effective here
bool push(node_t ** head, int val){
	node_t * new = malloc(sizeof(node_t));
	new->val = val;
	new->next = *head;
	*head = new;
	return true;
}

int main(int argc, char **argv) {
	node_t * head = malloc(sizeof(node_t));
	head->val=1;
	head->next = (node_t *)malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

	push(&head, 3);

	display(head);
	return 0;	
}

