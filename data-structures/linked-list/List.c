#include <stdlib.h>

#include "List.h"

/**
 *  Creates an empty struct list and returns it.
 */
struct list *ListNew(void) {
	struct list *newList = malloc(sizeof(*newList));
	newList->head = NULL;
	return newList;
}

/**
 *  Creates a new struct node with the given value and returns it.
 */
struct node *NodeNew(int value) {
	struct node *newNode = malloc(sizeof(*newNode));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

/**
 *  Appends a new struct node with the given value to the given list.
 *  Returns the head.
 */
struct node *ListAppend(struct node *root, int value) {
	if (root == NULL) return NodeNew(value);
	
	struct node *curr = root;
	for (; curr->next != NULL; curr = curr->next);
	curr->next = NodeNew(value);

	return root;
}

/**
 *  Prepends a new struct node with the given value to the given list.
 *  Returns the head.
 */
struct node *ListPrepend(struct node *root, int value) {
	if (root == NULL) return NodeNew(value);

	struct node *new = NodeNew(value);
	new->next = root;
	return new;
}

/**
 *  Deletes a struct node with the given value from the list.
 *  Returns the head.
 */
struct node *ListDelete(struct node *root, int value) {
	if (root == NULL) return NULL;

	if (root->value == value) {
		struct node *newHead = root->next;
		free(root);
		return newHead;
	}

	struct node *curr = root;
	for (; curr->next != NULL && curr->next->value != value; curr = curr->next);

	// value was not found
	if (curr->next == NULL) return root;

	struct node *toDelete = curr->next;
	curr->next = curr->next->next;
	free(toDelete);
	return root;
}

/**
 *  Returns whether the given list contains the given value.
 */
bool ListContains(struct node *root, int value) {
	if (root == NULL) return false;

	struct node *curr = root;
	for (; curr != NULL && curr->value != value; curr = curr->next);

	if (curr == NULL) return false;
	return true;
}

