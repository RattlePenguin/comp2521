#include <stdio.h>
#include <stdlib.h>

#include "AdjMatrix.h"
// #include "AdjList.h"

int main(void) {
	// Let's make a graph of size 5, with edges: 0<->1, 1<->2, 2<->0, 1<->3, 2<->4
	struct graph *g = GraphNew(5);
	GraphEdgeInsert(g, 0, 1);
	GraphEdgeInsert(g, 1, 2);
	GraphEdgeInsert(g, 0, 2);
	GraphEdgeInsert(g, 1, 3);
	GraphEdgeInsert(g, 2, 4);

	// Different implementations depending on graph type
	GraphPrint(g);
	
	return 0;
}
