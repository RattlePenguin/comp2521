#include <stdio.h>
#include <stdlib.h>

#include "AvlTree.h"

struct node *newNode(int value);
int getHeight(struct node *n);
int max(int x, int y);
int getBalanceFactor(struct node *n);
struct node *leftRotate(struct node *n);
struct node *rightRotate(struct node *n);

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

	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	n = AvlTreeRebalance(n);

	return n;
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
	return n->height;
}

/**
 *  Returns the maximum between two ints.
 *  If equal, first parameter is returned.
 */
int max(int x, int y) {
	return x >= y ? x : y;
}

struct node *AvlTreeRebalance(struct node *n) {
	if (n == NULL) return n;
	int nBF = getBalanceFactor(n);

	if (nBF > 1) { // left-heavy
		struct node *c = n->left;
		int cBF = getBalanceFactor(c);
		if (cBF < 0) n->left = leftRotate(c);
		n = rightRotate(n);
	} else if (nBF < -1) { // right-heavy
		struct node *c = n->right;
		int cBF = getBalanceFactor(c);
		if (cBF < 0) n->right = rightRotate(c);
		n = leftRotate(n);
	}

	return n;
}

/**
 *  Returns the balance factor of the given node.
 *  > 1 is left-heavy, < -1 is right-heavy.
 */
int getBalanceFactor(struct node *n) {
	if (n == NULL) return 0;
	return getHeight(n->left) - getHeight(n->right);
}

/**
 *  Performs a left BST rotation upon the given node.
 */
struct node *leftRotate(struct node *n) {
	if (n == NULL || n->right == NULL) return n;

	struct node *c = n->right;
	n->right = c->left;
	c->left = n;

	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	c->height = 1 + max(getHeight(c->left), getHeight(c->right));

	return c;
}

/**
 *  Performs a right BST rotation upon the given node.
 */
struct node *rightRotate(struct node *n) {
	if (n == NULL || n->left == NULL) return n;

	struct node *c = n->left;
	n->left = c->right;
	c->right = n;

	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	c->height = 1 + max(getHeight(c->left), getHeight(c->right));

	return c;
}

void AvlTreeDelete(AvlTree tree, int value) {
	tree->root = AvlTreeDeleteHelper(tree, tree->root, value);
}

struct node *AvlTreeDeleteHelper(AvlTree tree, struct node *n, int value) {
	if (n == NULL) return n;

	if (n->value < value) {
		
	} else if (n->value > value) {
	} else {
		struct node *s = findNextInOrder(tree, value);
	}
}

struct node *findNextInOrder(AvlTree tree, int value) {
	return NULL;
}

bool AvlTreeIsBalanced(AvlTree tree) {
	return AvlTreeIsBalancedHelper(tree->root);
}

bool AvlTreeIsBalancedHelper(struct node *n) {
	if (n == NULL) return true;
	return (abs(getHeight(n->left) - getHeight(n->right)) < 2) && AvlTreeIsBalancedHelper(n->left) && AvlTreeIsBalancedHelper(n->right);
}

void AvlTreePrint(AvlTree tree) {
	AvlTreePrintHelper(tree->root);
}

void AvlTreePrintHelper(struct node *n) {
	if (n == NULL) {
		return;
	}

	printf("%d\n", n->value);
	AvlTreePrintHelper(n->left);
	AvlTreePrintHelper(n->right);
}
