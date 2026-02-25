#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int listLength(struct node *list);

int main(void)
{
	printf("Enter number of nodes: ");
	int numNodes;
	scanf("%d", &numNodes);

	// Initialise first node in the list.
	struct node *head = NodeNew(0);

	// Initialise the other nodes and link them together.
	for (int i = 1; i < numNodes; ++i) {
		ListAppend(head, 0);
	}
	
	// Print the size of the list.
	int myListSize = listLength(head);
	printf("%d\n", myListSize);

	return 0;
}

// Recursively find the size of an acyclic linked list.
int listLength(struct node *list) {
}
