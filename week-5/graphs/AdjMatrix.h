#ifndef ADJMATRIX_H
#define ADJMATRIX_H
struct graph {
	int numNodes;
	int numEdges;

	int **edges; // could be bool for unweighted
};
#endif
