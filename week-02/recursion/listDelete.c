#include <stdio.h>
#include <stdlib.h>

#include "List.h"

struct node *listDelete(struct node *list, int val);

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
	
	printf("before:\n");
	ListPrint(head);
	printf("\n");

	printf("Enter node value to delete: ");
	int val;
	scanf("%d", &val);

	head = listDelete(head, val);

	printf("after:\n");
	ListPrint(head);

	return 0;
}

struct node *listDelete(struct node *list, int val) {
	return list;
}
