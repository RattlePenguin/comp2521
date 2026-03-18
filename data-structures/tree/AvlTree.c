#include <stdio.h>
#include <stdlib.h>

#include "AvlTree.h"

struct node *newNode(int value);
int getHeight(struct node *n);
int max(int x, int y);

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
	tree->root = AvlTreeInsertHelper(tree->root, value);
}

struct node *AvlTreeInsertHelper(struct node *n, int value) {
	if (n == NULL) {
		return newNode(value);
	}

	if (value < n->value) {
		n->left = AvlTreeInsertHelper(n->left, value);
	} else if (value > n->value) {
		n->right = AvlTreeInsertHelper(n->right, value);
	} else {
		return n; // no duplicates
	}

	n->height = getHeight(n);
	rebalance(n);

	return NULL;
}

/**
 *  Initialises a new AVL tree struct node with the given value.
 */
struct node *newNode(int value) {
	struct node *new = calloc(1, sizeof(*new));
	new->value = value;
	return new;
}

/**
 *  Checks and returns the height of a given node.
 */
int getHeight(struct node *n) {
	if (n == NULL) return -1;
	return 1 + max(getHeight(n->left), getHeight(n->right));
}

/**
 *  Returns the maximum between two ints.
 *  If equal, first parameter is returned.
 */
int max(int x, int y) {
	return x >= y ? x : y;
}

/**
 *  Rebalances an AVL tree assuming the given node is the root.
 */
void rebalance(struct node *n) {
	if (n == NULL) return;
	int balanceFactor = getHeight(n->left) - getHeight(n->right);

	
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
