#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Bst.h"

bool treeContains(struct node *tree, int value);
bool treeContainsRecursive(struct node *tree, int value);

int main(void) {
	struct node *tree = newNode(4);
	BstInsert(tree, 2);
	BstInsert(tree, 6);
	BstInsert(tree, 1);
	BstInsert(tree, 3);
	BstInsert(tree, 5);
	BstInsert(tree, 7);

	BstPrint(tree);
	
	for (int i = 0; i < 10; ++i) {
		if (treeContainsRecursive(tree, i)) {
			printf("tree contains %d\n", i);
		} else {
			printf("tree does not contain %d\n", i);
		}
	}
		return EXIT_SUCCESS;
}

/**
 *  Returns true if the given tree contains the given value, otherwise false.
 */
bool treeContains(struct node *tree, int value) {
	struct node *curr = tree;
	while (curr != NULL) {
		if (curr->value < value) {
			curr = curr->right;
		} else if (curr->value > value) {
			curr = curr->left;
		} else {
			return true;
		}
	}
	return false;
}

/**
 *  treeContains but recursive.
 */
bool treeContainsRecursive(struct node *tree, int value) {
	if (tree == NULL) {
		return false;
	}
	
	if (tree->value < value) {
		return treeContainsRecursive(tree->right, value);
	} else if (tree->value > value) {
		return treeContainsRecursive(tree->left, value);
	} else {
		return true;
	}
}
