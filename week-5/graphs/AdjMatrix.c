#include <stdlib.h>
#include <stdbool.h>

#include "AdjMatrix.h"

/**
 * Creates an empty graph of size numNodes.
 */
struct graph *GraphNew(int numNodes) {
	struct graph *g = calloc(1, sizeof(*g));
	g->numNodes = numNodes;
	
	// Empty graph
	g->edges = calloc(numNodes, sizeof(int *));
	for (int i = 0; i < numNodes; ++i) {
		g->edges[i] = calloc(numNodes, sizeof(int));
	}

	return g;
}

/**
 * Inserts an edge of weight 1 into graph g, between nodes x and y.
 */
bool GraphEdgeInsert(struct graph *g, int x, int y) {
	if (g->edges[x][y] != 0) {
		return false;
	}

	g->edges[x][y] = 1;
	g->edges[y][x] = 1;
	return true;
}
