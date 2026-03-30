#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "AdjMatrix.h"

/**
 * Creates an empty graph of size numNodes.
 */
Graph GraphNew(int numNodes) {
	Graph g = calloc(1, sizeof(*g));
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
void GraphFree(Graph g) {
	// Free edges
	for (int i = 0; i < g->numNodes; ++i) {
		free(g->edges[i]);
	}
	free(g->edges);
	free(g);
}

/**
 * Inserts an edge of weight 1 into graph g, from node x to node y.
 */
bool GraphEdgeInsert(Graph g, int x, int y) {
	if (g->edges[x][y] != 0) {
		return false;
	}

	g->edges[x][y] = 1;
	g->numEdges++;
	return true;
}

/**
 * Prints the adjacency matrix in human-readable format.
 * Breaks format when numNodes / edge weights exceeds double digits.
 */
void GraphPrint(Graph g) {
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
 *  Returns true if there exists an edge from node n to node m.
 */
bool GraphEdgeExists(Graph g, int n, int m) {
	if (g == NULL) {
		return false;
	}

	return g->edges[n][m] > 0;
}
