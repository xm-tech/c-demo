#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

// 输出链表每个节点的值
void display(node_t * head);

// 在链表尾部添加1节点
void push_end(node_t * head, int val);

// 在链表头部添加1节点
void push_head(node_t * head, int val);

// 在指定索引位置添加1节点
void push_any(node_t * head, int val);

// 删除表头的节点
int pop(node_t * head);

// 删除表尾的节点
int remove_end(node_t * head);

// 删除1指定索引位置的节点
int remove_index_node(node_t * head, int index);

// 查找是否包含某个值
bool search(node_t * head, int val);

// iterate a linkedlist
void display(node_t * head) {
	node_t * current = head;
	while (current != NULL) {
		printf("current.val=%d\n", current->val);
		current = current->next;
	}
}

int main(int argc, char **argv) {
	node_t * head = (node_t *)malloc(sizeof(node_t));
	if (head == NULL) {
		printf("malloc fail 1");
		return 1;
	}
	head->val=1;
	head->next = (node_t *)malloc(sizeof(node_t));
	if (head->next == NULL) {
		printf("malloc fail 2");
		return 2;
	}
	head->next->val = 2;
	head->next->next = NULL;

	display(head);
	return 0;	
}

