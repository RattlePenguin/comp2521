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
void AvlTreeFree(AvlTree tree);

/**
 *  Helper function for AvlTreeFree.
 *  Recursive free for nodes.
 */
void AvlTreeFreeHelper(struct node *n);

/**
 *  Inserts the given value into the given AVL tree.
 */
void AvlTreeInsert(AvlTree tree, int value);


/**
 *  Helper function for AvlTreeInsert.
 *  Recursively inserts nodes, and self-balances on unwind.
 */
struct node *AvlTreeInsertHelper(struct node *n, int value);

/**
 *  Rebalances an AVL tree assuming the given node is the root.
 *  Returns the new root if a rotation occurs.
 */
struct node *AvlTreeRebalance(struct node *n);

/**
 *  Deletes the given value from the given AVL tree.
 *  Returns true if value was found, else false.
 */
void AvlTreeDelete(AvlTree tree, int value);

/**
 *  Recursive node helper for AvlTreeDelete.
 */
struct node *AvlTreeDeleteHelper(struct node *n, int value);

/**
 *  Returns true if the given AVL tree contains the given value, else false.
 */
bool AvlTreeContains(AvlTree tree, int value);

/**
 *  Returns true if the given tree is balanced, else false.
 */
bool AvlTreeIsBalanced(AvlTree tree);

/**
 *  Helper function for AvlTreeIsBalanced.
 *  Recursively checks balance in all nodes.
 */
bool AvlTreeIsBalancedHelper(struct node *n);

/**
 *  Prints the given AVL tree PRE ORDER.
 */
void AvlTreePrint(AvlTree tree);
void AvlTreePrintHelper(struct node *n);

#endif
