#include <stdio.h>
#include "List.h"

int main(void)
{
	struct node *list = newList(5);
	
	int listSize = listSize(list);

	return 0;
}

// Recursively find the size of an acyclic linked list.
int listSize(struct node *list) {
	if (list == NULL) {
		return 0;
	}
	return listSize(list->next) + 1;
}
