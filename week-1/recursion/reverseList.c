#include <stdio.h>
#include <stdlib.h>

#include "List.h"

struct node *reverseList(struct node *head);

int main(void) {
	// Create a linked list of length 5 in ascending order {1,2...5}
	struct node *head = NULL;
	for (int i = 0; i < 5; ++i) {
		struct node *new = malloc(sizeof(*new));
		new->value = 5 - i;
		new->next = head;
		head = new;
	}

	// printList(head);
	
	head = reverseList(head);

	// printList(head);
}

/** Reverses a linked list recursively.
	This modifies the original list!
*/
struct node *reverseList(struct node *head) {
	// Base case
	// If list is empty or size 1, nothing happens.
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// Reverse the rest of the list.
	struct node *newHead = reverseList(head->next);

	// Old head still points to second, which should now be at the end.
	head->next->next = head;
	head->next = NULL;

	return newHead;
}
