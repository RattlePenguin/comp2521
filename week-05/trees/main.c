#include "AvlTree.h"

int main(void) {
	AvlTree tree = AvlTreeNew();
	
	AvlTreeInsert(tree, 0);

	AvlTreeFree(tree);
}
