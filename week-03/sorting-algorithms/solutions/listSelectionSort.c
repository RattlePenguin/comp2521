#include <stdio.h>

#include "List.h"

struct node *selectionSort(struct node *list);

int main(void) {
	struct node *list = NodeNew(5);
	ListAppend(list, 2);
	ListAppend(list, 3);
	ListAppend(list, 6);
	ListAppend(list, 1);
	ListAppend(list, 4);

	ListPrint(list);

	return 0;
}

struct node *selectionSort(struct node *list) {
	return list;
}
