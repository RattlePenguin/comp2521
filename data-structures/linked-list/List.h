#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// Linked List
struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
};

// Functions
struct list *ListNew(void);
struct node *NodeNew(int value);
struct node *ListAppend(struct node *root, int value);
struct node *ListPrepend(struct node *root, int value);
struct node *ListDelete(struct node *root, int value);
bool ListContains(struct node *root, int value);

#endif
