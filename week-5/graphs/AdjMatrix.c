#include <stdio.h>
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
 * Frees the given graph and all its components.
 */
void GraphFree(struct graph *g) {
	// Free edges
	for (int i = 0; i < g->numNodes; ++i) {
		free(g->edges[i]);
	}
	free(g->edges);
	free(g);
}

/**
 * Inserts an edge of weight 1 into graph g, between nodes x and y (bidirectional).
 */
bool GraphEdgeInsert(struct graph *g, int x, int y) {
	if (g->edges[x][y] != 0) {
		return false;
	}

	g->edges[x][y] = 1;
	g->edges[y][x] = 1;
	g->numEdges++;
	return true;
}

/**
 * Prints the adjacency matrix in human-readable format.
 * Breaks format past numNodes / edge weights in the double digits.
 */
void GraphPrint(struct graph *g) {
	
}
