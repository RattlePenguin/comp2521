# Introduction
Dijkstra's Algorithm uses a priority queue, visited set and distance array to calculate the shortest paths (in weight) from a source node to every other node.

Minimum Spanning Trees (MST) are acyclic subgraphs that contain the minimum sum of edge weights possible from the original graph.
This has practical use in mapping train or cable networks!
We use either Kruskal's or Prim's algorithm to find the MST of a graph.

# Topics
- Graphs
    - Dijkstra's Algorithm
    - Minimum Spanning Trees
        - Kruskal's Algorithm
        - Prim's Algorithm

## Dijkstra's Algorithm

## Minimum Spanning Trees
MSTs are called trees because an MST with V vertices will have V - 1 edges, allowing a tree shape to be formed.
A graph can have more than one MST.

### Kruskal's Algorithm
Kruskal's is a simple greedy algorithm.
The steps are as follows:
- Sort all graph edges by weight in ascending order.
- Starting from the edgeless graph:
    1. Add the next edge.
    2. If the graph forms a cycle, remove the edge just added.
    3. If V - 1 edges have been added, the MST is complete.
    4. Otherwise, repeat from step 1.

This ensures that the edges with the lowest weights are always considered next, minimising the total weight in the final result.

### Prim's Algorithm
