// Implement the following function to count number of internal nodes in a given tree.
// An internal node is a node with at least one child node.

#include <stdlib.h>

#include "Bst.h"

int bstCountInternal(struct node *t) {
	if (t == NULL || (t->left == NULL && t->right == NULL)) return 0;

	return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}
