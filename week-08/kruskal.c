typedef Graph MSTree;

MSTree kruskalFindMST(Graph g) {
	MSTree mst = GraphNew(g->nV); // MST initially empty
	Edge eList[g->nE]; // sorted array of edges
	edges(eList, g->nE, g);
	sortEdgeList(eList, g->nE);
	for (int i = 0; mst->nE < g->nV - 1; i++) {
		Edge e = eList[i];
		GraphAddEdge(mst, e);
		if (GraphHasCycle(mst)) GraphRemoveEdge(mst, e);
	}
	return mst;
}
