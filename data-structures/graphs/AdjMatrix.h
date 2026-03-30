#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include <stdbool.h>

typedef struct graph {
	int numNodes;
	int numEdges;

	int **edges; // could be bool for unweighted
} *Graph;

struct graph *GraphNew(int numNodes);
bool GraphEdgeInsert(struct graph *g, int x, int y);
void GraphPrint(struct graph *g);
#endif
