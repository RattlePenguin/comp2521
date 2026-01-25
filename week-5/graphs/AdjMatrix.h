#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include <stdbool.h>

struct graph {
	int numNodes;
	int numEdges;

	int **edges; // could be bool for unweighted
};

struct graph *GraphNew(int numNodes);
bool GraphEdgeInsert(struct graph *g, int x, int y);
#endif
