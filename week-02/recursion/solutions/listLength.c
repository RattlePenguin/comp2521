/**
 *  Write a recursive function to compute the length of a linked list.
 */

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int listLength(struct node *l);

int main(void)
{
	printf("Enter number of nodes: ");
	int numNodes;
	scanf("%d", &numNodes);

	// Initialise first node in the list.
	struct node *head = NodeNew(0);

	// Initialise the other nodes and link them together.
	for (int i = 1; i < numNodes; ++i) {
		ListAppend(head, i);
	}
	
	// Print the length of the list.
	int myListLength = listLength(head);
	printf("%d\n", myListLength);

	return 0;
}

// Recursively find the size of an acyclic linked list.
int listLength(struct node *l) {
	if (l == NULL) return 0;
	return 1 + listLength(l->next);
}
