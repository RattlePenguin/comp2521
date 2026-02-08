#include <stdio.h>

#include "Bst.h"

int main(void) {
	printf("Enter number of nodes: ");

	int numNodes = 0;
	if (scanf("%d", &numNodes) <= 0) {
		return 0;
	}

	printf("Enter node values (separated by spaces): ");

	struct node *root = NULL;
	for (int i = 0; i < numNodes; ++i) {
		int value = 0;
		if (scanf("%d", &value)) {
			root = BstInsert(root, value);
		}
	}

	BstPrint(root);

	return 0;
}
