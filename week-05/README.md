# Introduction
Rotations are a way for BSTs to resolve balance, keeping its operations O(logn) time.
AVL trees are self-balancing BSTs, performing rotations when necessary upon insertion or deletion.

Make sure you know the three representations of graphs, their pros and their cons (this means complexity).
You should be comfortable implementing each representation and these operations:
- Inserting and deleting an edge
- Checking a node's neighbours
- Traversals. BFS and DFS (later)

# Reminders
- Get going on Assignment 1 please.
- Enjoy your flex week!

# Topics
- BST
    - Rotations
    - AVL Trees
- Graphs
    - Adj Matrix
    - Adj List
    - Array of Edges

## Rotations
Rotations involve moving nodes (and as a result, their children) in a BST to shift height around.
There's left and right rotations.
The best way to practise this is to draw out a BST and perform each step of the rotation on it.

## AVL Trees
AVL Trees self-balance by recursively checking "heavyness", from the site of insertion or deletion up towards the root.
We do this by comparing the difference between heights in the left subtree and the right subtree.
This is called the Balance Factor (BF).
In this course, $BF = leftHeight - rightHeight$.
If the $|BF|$ of any node is greater than 1, then this node is unbalanced and requires a rotation.

There are four types of imbalance that require different rotations.
- Left Left (LL)
- Right Right (RR)
- Left Right (LR)
- Right Left (RL)

LL and RR only perform a single rotation, while LR and RL perform two rotations (double rotation).

## Graphs
Graphs are like the ultimate evolution of pointer data structures after linked lists and trees.
In trees, we simply added another pointer to the linked list node.
In graphs, we may have an almost infinite number of neighbours spanning from one node.

There are a lot of concepts when considering graphs.
You should be able to define these terms:
- Path and Cycle
- Degree
- Clique
- Weighted Graphs 
- Directed Graphs

Since we cannot finitely determine how many neighbours a node will have, how can we represent a graph?

### Adjacency Matrix
Adjacency matrices use a 2D array to represent edges between nodes.
This is simple as no additional node struct is required, the length of the 2D array is equal to the number of nodes.

This allows us to find, insert and delete edges in O(1) time.

### Adjacency List
Adjacency lists combine a node struct (e.g. adjNode) and an array containing pointers.
The adjNode acts as a linked list, while the array indices represent each node id.
For example, the graph contains an `struct adjNode **edges` field.
`edges[1]` is a pointer to the linked list of neighbours of node `1`.
If it is `NULL`, node `1` has no neighbours, otherwise it is the first neighbour adjNode.

This representation takes O(n) time to find, insert and delete edges, due to the traversal of the linked list.

### Array of Edges
Array of edges simply stores every edge that exists in the graph.
This can be done using structs, additional arrays or otherwise.

This representation takes O(E) time to find and delete edges, and O(1) time to add an edge.
