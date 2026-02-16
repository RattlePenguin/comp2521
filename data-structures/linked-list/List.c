#include <stdlib.h>

#include "List.h"

struct list *ListNew(void) {
	struct list *newList = malloc(sizeof(*newList));
	newList->head = NULL;
	return newList;
}

struct node *NodeNew(int value) {
	struct node *newNode = malloc(sizeof(*newNode));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}
