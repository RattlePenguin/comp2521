# Introduction
Dijkstra's Algorithm uses a priority queue, visited set and distance array to calculate the shortest paths (in weight) from a source node to every other node.
It does not work for negative weights.

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
Dijkstra's Algorithm is a little complex, but with some practice you should be able to understand it well.
Remember that the goal is to find the shortest path to every other node, from a source node.

Dijkstra's will process every vertex in the graph once.
The next vertex at each step must have the minimum distance from the source node (unvisited).
It then updates distances if it can find a better path.
By greedily picking minimum distances first, we never end up on a longer path before a shorter one while processing the current vertex.
- Initialise vertex set `vSet` with all vertices
- Initialise distance array `distance` with `INT_MAX`, except `src` which will have `0`
- Initialise predecessors `pred` with `-1`
- While `vSet` is not empty:
    - Pop the `v` with the minimum `distance`.
    - For each of its **unvisited** neighbours, perform edge relaxation.
    - If edge relaxation does occur, update the neighbour's predecessor to `v`.

Dijkstra's does not work for negative weights.
Being a greedy algorithm, it never reconsiders visited vertices.
As such, it might miss a shorter path that is discovered later!

## Minimum Spanning Trees
MSTs are called trees because an MST with V vertices will have V - 1 edges, allowing a tree shape to be formed.
A graph can have more than one MST.

Kruskal and Prim's Algorithm are greedy algorithms that pick the minimum edge weight at every stage, to achieve a global minimum sum of edge weights.

### Kruskal's Algorithm
Kruskal's Algorithm finds MSTs by adding edges in ascending order and preventing cycles at all times.

The steps are as follows:
- Sort all graph edges by weight in ascending order ( $O(E log E)$ )
- Starting from the edgeless graph:
    1. Add the next edge.
    2. If the graph forms a cycle, remove the edge just added.
        - If using DFS, this is $O(V + E)$
        - With Union-Find, this is practically $O(1)$
    3. If V - 1 edges have been added, the MST is complete.
    4. Otherwise, repeat from step i.

This ensures that the edges with the lowest weights are always considered next, minimising the total weight in the final result.
Since an MST is possible at $E = V - 1$, Kruskal's may be faster than Prim's for sparse graphs (lower $E$).

### Prim's Algorithm
Prim's is slightly more implementation heavy than Kruskal's.

- Begin with an empty graph - no vertices or edges
- Start by adding any vertex of choice
- While the MST does not contain all vertices: $O(V)$
    - Add an edge with one vertex in the MST and the other not, with the minimum weight. Add this vertex to the MST.
        - Finding the minimum edge is $O(E)$, but can be reduced to $O(logE)$ with a Fibonacci heap.
