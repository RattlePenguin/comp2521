// Implement the following function that counts the number of values that are greater than a given value.
// This function should access as few nodes as possible.

#include <stdlib.h>

#include "Bst.h"

int bstCountGreater(struct node *t, int val) {
	if (t == NULL) return 0;

	if (t->value < val) {
		return bstCountGreater(t->right, val);
	}
	return 1 + bstCountGreater(t->right, val);
}
