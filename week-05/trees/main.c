#include "AvlTree.h"

int main(void) {
	AvlTree tree = AvlTreeNew();
	
	AvlTreeInsert(tree, 0);
	AvlTreeInsert(tree, 1);
	AvlTreeInsert(tree, 2);
	AvlTreeInsert(tree, 3);
	AvlTreeInsert(tree, 4);

	AvlTreeFree(tree);
}
