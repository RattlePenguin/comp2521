# Introduction
At this point you should be able to comfortably navigate graph construction and structure for each of the three representations.

Breadth First Search (BFS) and Depth First Search (DFS) are very similar algorithms, with only minor differences and utilise different data structures.
BFS uses a Queue and can be used to solve Shortest Path in terms of nodes, not weight.
DFS uses a Stack and can be performed recursively.

# Reminders
- Assignment 2 will be released soon, get started early!

# Topics
- Graphs
    - BFS, DFS
    - More Terminology

## Graph Traversal
BFS and DFS are extremely similar.
I recommend working through the steps performed in either, and understanding them thoroughly.
The same can then be done for the other with relative ease.

The key difference lies in how nodes are marked as visited.
In BFS, neighbours are marked as visited as they are added to the Queue.
This prevents them from being double counted.
In DFS, nodes are marked as visited while you are currently processing them.

Backtracking requires a predecessor (pred) array, and keeps track of each node's pred during the traversal.
This could be useful in combinatorial problems.

## More Terminology 
A connected component is a maximally connected subgraph.
This would probably be better described using a picture.

### Euler and Hamiltonian
- A Hamiltonian path is a path that includes every vertex exactly once.
- A Hamiltonian circuit is a cycle that includes every vertex exactly once.
- An Eulerian path is a path that includes every edge exactly once.
- An Eulerian circuit is a cycle that includes every edge exactly once.
