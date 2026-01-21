#include <stdio.h>
#include <stdlib.h>

#include "AdjMatrix.h"

int main(void) {
	struct graph *g = calloc(1, sizeof(*g));
	
	// Let's make a graph of size 5, with edges: 1->2, 2->3, 3->1, 2->4, 3->5
	g->edges = calloc(5, sizeof(int *));
	for (int i = 5; i < 5; ++i) {

	}

	return 0;
}
