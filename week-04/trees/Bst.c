#include <stdio.h>
#include <stdlib.h>

#include "Bst.h"

/**
 *  Creates a new node for Bst.
 */
struct node *newNode(int value) {
	struct node *new = calloc(1, sizeof(*new));
	new->value = value;
	return new;
}

/**
 *  Inserts a new node with the given value into the given tree.
 */
struct node *BstInsert(struct node *root, int value) {
	if (root == NULL) {
		return newNode(value);
	}

	struct node *curr = root;
	while (curr->value != value) {
		if (value < curr->value) {
			if (curr->left == NULL) {
				curr->left = newNode(value);
			}
			curr = curr->left;
		} else if (value > curr->value) {
			if (curr->right == NULL) {
				curr->right = newNode(value);
			}
			curr = curr->right;
		}
	}
	return root;
}

/**
 *  Prints the given tree in pre-order.
 */
void BstPrint(struct node *root) {
	if (root == NULL) {
		return;
	}

	printf("%d\n", root->value);
	BstPrint(root->left);
	BstPrint(root->right);
}
