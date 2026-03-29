#include <stdio.h>
#include <stdlib.h>

#include "AvlTree.h"

struct node *newNode(int value);
int getHeight(struct node *n);
int max(int x, int y);
int getBalanceFactor(struct node *n);
struct node *leftRotate(struct node *n);
struct node *rightRotate(struct node *n);
struct node *findNextInOrder(struct node *n);

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
	return AvlTreeRebalance(n);
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
		if (getBalanceFactor(n->left) < 0) n->left = leftRotate(n->left);
		n = rightRotate(n);
	} else if (nBF < -1) { // right-heavy
		if (getBalanceFactor(n->right) > 0) n->right = rightRotate(n->right);
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
	tree->root = AvlTreeDeleteHelper(tree->root, value);
}

struct node *AvlTreeDeleteHelper(struct node *n, int value) {
	if (n == NULL) return n;

	if (n->value < value) {
		n->right = AvlTreeDeleteHelper(n->right, value);
	} else if (n->value > value) {
		n->left = AvlTreeDeleteHelper(n->left, value);
	} else {
		if (n->left == NULL) {
			struct node *r = n->right;
			free(n);
			return r;
		} else if (n->right == NULL) {
			struct node *r = n->left;
			free(n);
			return r;
		}
		
		// two children
		struct node *s = findNextInOrder(n);
		n->value = s->value;
		n->right = AvlTreeDeleteHelper(n->right, s->value);
	}

	n->height = 1 + max(getHeight(n->left), getHeight(n->right));
	return AvlTreeRebalance(n);
}

/**
 *  Returns the next in-order successor node of the given node.
 *  Precondition: n must have a right child.
 */
struct node *findNextInOrder(struct node *n) {
	if (n == NULL) return n;
	struct node *curr = n->right;
	while (curr->left != NULL) curr = curr->left;
	return curr;
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
