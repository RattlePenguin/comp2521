// Implement the following function that returns the level of the node containing a given key if such a node exists.
// Otherwise the function returns -1 (when a given key is not in the binary search tree).
// The level of the root node is zero.

#include <stdlib.h>

#include "Bst.h"

int bstNodeLevel(struct node *t, int key) {
	if (t == NULL) return -1;

	int res;
	if (t->value > key) {
		res = bstNodeLevel(t->left, key);
	} else if (t->value < key) {
		res = bstNodeLevel(t->right, key);
	} else {
		return 0;
	}

	if (res != -1) return 1 + res;
	return res;
}

