#include <stdio.h>
#include <stdlib.h>

#include "AvlTree.h"

struct node *newNode(int value);
int getHeight(struct node *n);
int max(int x, int y);
int getBalanceFactor(struct node *n);
struct node *rotateLeft(struct node *n);
struct node *rotateRight(struct node *n);

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

	n->height = max(getHeight(n->left), getHeight(n->right));
	n = AvlTreeRebalance(n);

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
	int bf = getBalanceFactor(n);

	if (bf > 1) { // left heavy
		if (getBalanceFactor(n->left) < 0) { // right heavy
			n->left = rotateLeft(n->left);
		}
		
		return rotateRight(n);
	} else if (bf < -1) { // right heavy
		if (getBalanceFactor(n->right) > 0) { // left heavy
			n->left = rotateRight(n->left);
		}
		
		return rotateLeft(n);
	}
	return n;
}

/**
 *  Rotates left from the given node as root.
 */
struct node *rotateLeft(struct node *n) {
	struct node *newRoot = n->right;

	n->right = newRoot->left;
	newRoot->left = n;
	
	n->height = getHeight(n);
	newRoot->height = getHeight(newRoot);

	return newRoot;
}

/**
 *  Rotates right from the given node as root.
 */
struct node *rotateRight(struct node *n) {
	struct node *newRoot = n->left;

	n->left = newRoot->right;
	newRoot->right = n;
	
	n->height = getHeight(n);
	newRoot->height = getHeight(newRoot);

	return newRoot;
}

/**
 *  Returns the balance factor of the given node.
 */
int getBalanceFactor(struct node *n) {
	if (n == NULL) return 0;
	return getHeight(n->left) - getHeight(n->right);
}

void AvlTreeDelete(AvlTree tree, int value) {
	tree->root = AvlTreeDeleteHelper(tree->root, value);
}

struct node *AvlTreeDeleteHelper(struct node *n, int value) {
	if (n == NULL) return n;

	if (value < n->value) {
		n->left = AvlTreeDeleteHelper(n->left, value);
	} else if (value > n->value) {
		n->right = AvlTreeDeleteHelper(n->right, value);
	} else {
		// TODO
	}

	n->height = max(getHeight(n->left), getHeight(n->right));
	n = AvlTreeRebalance(n);

	return NULL;
}

bool AvlTreeIsBalanced(AvlTree tree) {
	return AvlTreeIsBalancedHelper(tree->root);
}

bool AvlTreeIsBalancedHelper(struct node *n) {
	if (n == NULL) return true;
	return (abs(getBalanceFactor(n)) < 2) && AvlTreeIsBalancedHelper(n->left) && AvlTreeIsBalancedHelper(n->right);
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
