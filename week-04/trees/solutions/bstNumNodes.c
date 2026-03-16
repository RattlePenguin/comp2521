// Write a recursive function to count the total number of nodes in a tree.

#include <stdlib.h>

#include "Bst.h"

int bstNumNodes(struct node *t) {
	if (t == NULL) return 0;

	return 1 + bstNumNodes(t->left) + bstNumNodes(t->right);
}
