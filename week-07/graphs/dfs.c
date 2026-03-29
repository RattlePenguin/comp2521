dfs(G, src):
    Input: graph G, vertex src
    
    create visited array, initialised to false
    create predecessor array, initialised to -1
    create stack S
    
    push src onto S
    
    while S is not empty:
        pop v from S
        if v has been visited:
            continue
        
        mark v as visited
        
        for each neighbour w of v
                (in decreasing order):
            if w has not been visited:
                set predecessor of w to v
                push w onto S
