#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

struct node *newNode(int value) {
	struct node *new = calloc(1, sizeof(*new));
	
	new->value = value;

	return new;
}

struct node *bstInsert(struct node *root, int value) {
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

void bstPrint(struct node *root) {
	if (root == NULL) {
		return;
	}

	printf("%d\n", root->value);
	bstPrint(root->left);
	bstPrint(root->right);
}
