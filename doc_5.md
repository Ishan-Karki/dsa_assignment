# Documentation for Graph Traversal: BFS and DFS (Question 5)

## Data Structures

The program represents an **Undirected Graph** using an **Adjacency Matrix**:

```c
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;
```

- `adjMatrix`: A 2D array where `adjMatrix[i][j] = 1` indicates an edge between vertex `i` and vertex `j`, and 0 otherwise.
- `numVertices`: The total number of vertices currently in the graph.

## Functions

1.  **`void initGraph(Graph *g, int vertices)`**: Initializes the graph with a specified number of vertices and sets all entries in the adjacency matrix to 0 (no edges).
2.  **`void addEdge(Graph *g, int src, int dest)`**: Adds an undirected edge between `src` and `dest`. Since the graph is undirected, it sets both `adjMatrix[src][dest]` and `adjMatrix[dest][src]` to 1.
3.  **`void bfs(Graph *g, int startVertex)`**: Implements the **Breadth-First Search** algorithm.
    - Uses a `queue` (implemented as an array) to explore vertices level by level.
    - Uses a `visited` array to keep track of visited vertices to avoid cycles and redundant processing.
    - Enqueues the starting vertex, marks it visited, and then iteratively dequeues a vertex, visits its unvisited neighbors, marks them visited, and enqueues them.
4.  **`void dfs(Graph *g, int startVertex)`**: Implements the **Depth-First Search** algorithm.
    - Serves as a wrapper function that initializes the `visited` array.
    - Calls the recursive helper function `dfsRecursive` to perform the traversal.
5.  **`void dfsRecursive(Graph *g, int vertex, int visited[])`**: The recursive core of DFS.
    - Marks the current vertex as visited and prints it.
    - Recursively calls itself for all unvisited adjacent vertices.

## Main Function Organization

The `main()` function:
1.  Initializes a graph with 5 vertices (0 to 4).
2.  Adds edges to form a connected structure:
    - (0, 1), (0, 2)
    - (1, 3), (1, 4)
    - (2, 3)
    - (3, 4)
3.  Demonstrates BFS starting from vertex 0.
4.  Demonstrates DFS starting from vertex 0.

## Sample Output

```text
--- Graph Traversal (Adjacency Matrix) ---

Breadth First Search (starting from vertex 0):
0 1 2 3 4 

Depth First Search (starting from vertex 0):
0 1 3 2 4 
```
