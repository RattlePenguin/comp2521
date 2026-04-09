// BFS
Set reachable(Graph g, Vertex src) {
	Set seen = SetNew();
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	SetAdd(seen, src);
	
	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		
		for (Vertex w = 0; w < g->nV; w++) {
			if (g->edges[v][w] && !SetContains(seen, w)) {
				QueueEnqueue(q, w);
				SetAdd(seen, w);
			}
		}
	}
	return seen;
}

// Recursive DFS
Set reachable(Graph g, Vertex src) {
	Set seen = SetNew();
	doReachable(g, src, seen);
	return seen;
}

static void doReachable(Graph g, Vertex v, Set seen) {
	SetAdd(seen, v);
	
	for (Vertex w = 0; w < g->nV; w++) {
		if (g->edges[v][w] && !SetContains(seen, w)) {
			doReachable(g, w, seen);
		}
	}
}
