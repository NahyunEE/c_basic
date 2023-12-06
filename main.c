#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { 
	TRUE = 1, True = TRUE, true = True,
	FALSE = 0, False = FALSE, false = False
} bool_t;

typedef struct _stack stack_t;
typedef struct _node node_t;

struct _stack {
	int count;
	node_t *head;
};

struct _node {
	int data;
	node_t *next;
};

node_t *makeNode(int data);
bool_t push(stack_t *stack, node_t *node);
int pop(stack_t *stack, int *error);
void show(stack_t *stack);

int main() {
	
	stack_t stack = { 0, NULL };
	node_t *node = makeNode(10);
	if (node == NULL) {
		return 1;
	}
	if (!push(&stack, node)) {
		fprintf(stderr, "입력에 실패하였습니다.\n");
	}
	else {
		printf("스텍에 데이터를 저장하였습니다.");
	}
	
	int pop_data = pop(&stack);
	if (errno != 0) {
		
	}

	
	return 0;
}

node_t *makeNode(int data) {
	node_t *node = (node_t *)calloc(1, sizeof(node_t));
	if (node == NULL) {
		fprintf(stderr, "동적할당에 실패하였습니다\n");
		return NULL;
	}
	node->data = data;
	return node;
}

bool_t push(stack_t *stack, node_t *node) {
	if (node == NULL) {
		fprintf(stderr, "NULL 포인터가 입력되었습니다.\n");
		return false;
	}
	node->next = stack->head;
	stack->head = node; 
	stack->count++;
	return true;
}

int pop(stack_t *stack) {
	if (stack->head == NULL) {
		fprintf(stderr, "스텍에 저장된 데이터가 없습니다.\n");
		return 0;
	}
	return 0;
}

void show(stack_t *stack) {
	
}



