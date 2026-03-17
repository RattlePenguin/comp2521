#include <stdio.h>
#include <stdlib.h>

#include "AvlTree.h"

struct node *newNode(int value) {
	struct node *new = calloc(1, sizeof(*new));
	new->value = value;
	return new;
}

AvlTree AvlTreeNew() {
	AvlTree tree = calloc(1, sizeof(struct avlTree));
	return tree;
}

void AvlTreeFree(AvlTree tree) {
	AvlTreeFreeHelper(tree->root);
	free(tree);
}

void AvlTreeFreeHelper(struct node *n) {
	if (n == NULL) return;
	AvlTreeFreeHelper(n->left);
	AvlTreeFreeHelper(n->right);
	free(n);
}

void AvlTreeInsert(AvlTree tree, int value) {
	tree->root = 
}

struct node *AvlTreeInsertHelper(struct node *n, int value) {
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
