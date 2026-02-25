/**
 *  Write a recursive function to count the number of odd numbers in a linked list.
 */

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int listCountOdds(struct node *l);

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
	
	// Print the number of odd numbers in list.
	int numOdds = listCountOdds(head);
	printf("%d\n", numOdds);

	return 0;
}

// Recursively return the number of odd numbers in a linked list.
int listCountOdds(struct node *l) {
}
