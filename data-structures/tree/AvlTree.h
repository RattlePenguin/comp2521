#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

struct node {
	int value;
	int height;
	struct node *left;
	struct node *right;
};

typedef struct avlTree {
	struct node *root;
} *AvlTree;

/**
 *  Creates an empty AVL tree.
 */
AvlTree AvlTreeNew();

/**
 *  Frees a given AVL tree and its components.
 */
void AvlTreeFree();

/**
 *  Helper function for AvlTreeFree.
 *  Recursive free for nodes.
 */
void AvlTreeFreeHelper();

/**
 *  Inserts the given value into the given AVL tree.
 */
void AvlTreeInsert(AvlTree tree, int value);

/**
 *  Deletes the given value from the given AVL tree.
 *  Returns true if value was found, else false.
 */
void AvlTreeDelete(AvlTree tree, int value);

/**
 *  Returns true if the given AVL tree contains the given value, else false.
 */
bool AvlTreeContains(AvlTree tree, int value);

/**
 *  Prints the given AVL tree PRE ORDER.
 */
void AvlTreePrint(AvlTree tree);

#endif
