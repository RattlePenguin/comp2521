#include <stdio.h>
#include <stdlib.h>

#include "List.h"

void printList(struct node *head);

int main(void) {
	// Create a linked list of length 5 in ascending order {1,2...5}
	struct node *head = NULL;
	for (int i = 0; i < 5; ++i) {
		struct node *new = malloc(sizeof(*new));
		new->value = 5 - i;
		new->next = head;
		head = new;
	}

	// Print the linked list
	printList(head);

	return 0;
}

void printList(struct node *head) {
	if (head == NULL) {
		return;
	}

	printf("%d ", head->value);

	printList(head->next);
}
