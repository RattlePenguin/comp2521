#ifndef ADJLIST_H
#define ADJLIST_H

// Adjacency node, similar to linked list node
struct adjNode {
	int value;
	struct adjNode *next;
};

struct graph {
	int numNodes;
	int numEdges;
	struct adjNode **adjList; // array of adjNode pointers
};

#endif
