// Write a recursive function to compute the height of a tree.
// The height of a tree is defined as the length of the longest path from the root to a leaf.
// The path length is a count of the number of links (edges) on the path.
// The height of an empty tree is -1.

#include <stdlib.h>

#include "Bst.h"

int max(int x, int y) {
	if (x > y) return x;
	return y;
}

int bstHeight(struct node *t) {
	if (t == NULL) return -1;

	return 1 + max(bstHeight(t->left), bstHeight(t->right));
}
