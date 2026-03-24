// Implement a function that checks whether a given linked list has a cycle in it.

#include <stdio.h>

#include "List.h"

bool isListCyclic(struct node *l);

int main(void) {
	struct node *l = NULL;
	printf("Enter number of nodes for l: ");
	int input;
	scanf("%d", &input);

	printf("Enter node values (separated by spaces): ");
	for (int i = 0; i < input; ++i) {
		int value;
		scanf("%d", &value);
		if (l == NULL) {
			l = NodeNew(value);
		} else {
			ListAppend(l, value);
		}
	}

	if (isListCyclic(l)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	return 0;
}

bool isListCyclic(struct node *l) {
	return false;
}
