bfs(G, src):
    Input: graph G, vertex src
    
    create visited array, initialised to false
    create predecessor array, initialised to -1
    create queue Q
    
    mark src as visited
    enqueue src into Q
    
    while Q is not empty:
        dequeue v from Q
        
        for each neighbour w of v:
            if w has not been visited:
                mark w as visited
                set predecessor of w to v
                enqueue w into Q
