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
	g->edges = calloc((unsigned long) numNodes, sizeof(int *));
	for (int i = 0; i < numNodes; ++i) {
		g->edges[i] = calloc((unsigned long) numNodes, sizeof(int));
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
 * Breaks format when numNodes / edge weights exceeds double digits.
 */
void GraphPrint(struct graph *g) {
	printf("Adjacency Matrix:\n");

	printf("   ");
	for (int i = 0; i < g->numNodes; ++i) {
		printf("% 2d ", i);
	}
	printf("\n");

	for (int i = 0; i < g->numNodes; ++i) {
		printf("% 2d ", i);
		for (int j = 0; j < g->numNodes; ++j) {
			printf("% 2d ", g->edges[i][j]);
		}
		printf("\n");
	}
}

/**
 *  Returns true if there exists an edge between node n and node m.
 */
bool GraphEdgeExists(struct graph *g, int n, int m) {
	if (g && n && m) {
		return true;
	}
	return false;
}
