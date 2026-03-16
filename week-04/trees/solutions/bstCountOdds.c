// Implement the following function that counts the number of odd values in a tree.

#include <stdlib.h>

#include "Bst.h"

int bstCountOdds(struct node *t) {
	if (t == NULL) return 0;

	if (t->value % 2 != 0) {
		return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
	}
	return bstCountOdds(t->left) + bstCountOdds(t->right);
}
