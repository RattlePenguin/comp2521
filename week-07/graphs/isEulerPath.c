#include <stdio.h>
#include <stdbool.h>

#include "AdjMatrix.h"

struct edge {
	int v;
	int w;
};

// check whether a given path is a Euler path
bool isEulerPath(Graph g, struct edge e[], int nE) {
	if (g && e && nE) return false;
	return false;
}

int main(void) {
	Graph g = GraphNew(4);
	GraphEdgeInsert(g, 0, 1);
	GraphEdgeInsert(g, 1, 2);
	GraphEdgeInsert(g, 2, 3);
	GraphEdgeInsert(g, 3, 1);

	struct edge path[4] = { {0, 1}, {1, 2}, {2, 3}, {3, 1} };

	if (isEulerPath(g, path, 4)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}

	return 0;
}
