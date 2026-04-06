#include "AdjMatrix.h"

int main(void) {
	Graph g = GraphNew(10);
	GraphEdgeInsert(g, 0, 1);
	GraphEdgeInsert(g, 0, 2);
	GraphEdgeInsert(g, 0, 3);
	GraphEdgeInsert(g, 2, 1);
	GraphEdgeInsert(g, 2, 3);
	GraphEdgeInsert(g, 2, 5);
	GraphEdgeInsert(g, 3, 0);
	GraphEdgeInsert(g, 3, 4);
	GraphEdgeInsert(g, 4, 2);
	GraphEdgeInsert(g, 4, 5);
	GraphEdgeInsert(g, 4, 7);
	GraphEdgeInsert(g, 4, 8);
	GraphEdgeInsert(g, 5, 1);
	GraphEdgeInsert(g, 6, 5);
	GraphEdgeInsert(g, 6, 7);
	GraphEdgeInsert(g, 6, 9);
	GraphEdgeInsert(g, 7, 4);
	GraphEdgeInsert(g, 7, 5);
	GraphEdgeInsert(g, 7, 8);
	GraphEdgeInsert(g, 8, 7);
	GraphEdgeInsert(g, 9, 7);
	GraphEdgeInsert(g, 9, 8);

	Set s0 = reachable(g, 0);
	SetPrint(s0);

	return 0;
}
Set reachable(Graph g, Vertex src) {
	Set s = SetNew();
	if (g == NULL || g->numNodes <= src) return s;
}
