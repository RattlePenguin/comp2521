#ifndef TREE_H
#define TREE_H

struct node {
	int value;
	struct node *left;
	struct node *right;
};

struct node *newNode(int value);
struct node *bstInsert(struct node *root, int value);
void bstPrint(struct node *root);

#endif
