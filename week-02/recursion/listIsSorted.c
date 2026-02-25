#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "List.h"

bool listIsSorted(struct node *l);

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
	
	// Print whether the list is sorted.
	bool isSorted = listIsSorted(head);
	
	if (isSorted) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}

	return 0;
}

// Recursively find whether the given list is sorted.
bool listIsSorted(struct node *l) {
}
