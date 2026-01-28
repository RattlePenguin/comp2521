#ifndef LIST_H
#define LIST_H

// Linked List
struct node {
	int value;
	struct node *next;
};

// Linked List funny version
struct list {
	struct node *head;
};

#endif
