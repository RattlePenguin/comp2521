// https://leetcode.com/problems/add-two-numbers

#include <stdio.h>

#include "List.h"

struct node *addTwoNumbers(struct node *l1, struct node *l2);

int main(void) {
	struct node *l1 = NULL;
	printf("Enter number of nodes for l1: ");
	int input;
	scanf("%d", &input);

	printf("Enter node values (separated by spaces): ");
	for (int i = 0; i < input; ++i) {
		int value;
		scanf("%d", &value);
		if (l1 == NULL) {
			l1 = NodeNew(value);
		} else {
			ListAppend(l1, value);
		}
	}

	struct node *l2 = NULL;
	printf("Enter number of nodes for l2: ");
	scanf("%d", &input);

	printf("Enter node values (separated by spaces): ");
	for (int i = 0; i < input; ++i) {
		int value;
		scanf("%d", &value);
		if (l2 == NULL) {
			l2 = NodeNew(value);
		} else {
			ListAppend(l2, value);
		}
	}

	struct node *res = addTwoNumbers(l1, l2);

	for (struct node *curr = res; curr != NULL; curr = curr->next) printf("%d ", curr->value);
	printf("\n");
	return 0;
}

struct node *addTwoNumbers(struct node *l1, struct node *l2) {
	return NULL;
}
