#include <stdbool.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

// 输出链表每个节点的值
void display(node_t * head);

// 表头添加
bool push(node_t ** head, int val);

// 表尾删除
int pop(node_t * head);

// 删除1指定索引位置的节点
int remove_index(node_t * head, int index);

// 查找是否包含某个值
bool search(node_t * head, int val);


