// Pseudocode for Prim's Algorithm

Start from any vertex v and empty MST
Choose edge not already in MST, satisfying

    incident on a vertex s already in MST
    incident on a vertex t not already in MST
    with minimal weight of all such edges

Add chosen edge to MST
Repeat until MST covers all vertices
