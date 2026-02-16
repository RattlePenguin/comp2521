#ifndef LIST_H
#define LIST_H

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

#endif
