# Documentation for Dijkstra's Algorithm (Question 7)

## Data Structures

The program represents a **Weighted Graph** using an **Adjacency Matrix**:

```c
int graph[V][V];
```

- `V`: The number of vertices (defined as 9 in this example).
- `graph[i][j]`: Stores the weight of the edge between vertex `i` and vertex `j`. A value of `0` indicates no edge (except for the diagonal `i==j`).

## Functions

1.  **`int minDistance(int dist[], bool sptSet[])`**: A utility function to find the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree (`sptSet`).
2.  **`void dijkstra(int graph[V][V], int src)`**: The core implementation of Dijkstra's algorithm.
    - Initializes distances to infinity (`INT_MAX`) and `sptSet` to false.
    - Iteratively selects the unvisited vertex with the smallest distance.
    - Updates the distances of its adjacent vertices if a shorter path is found ("relaxation").
3.  **`void printSolution(int dist[])`**: Displays the final shortest distances from the source to all other vertices.

## Main Function Organization

The `main()` function:
1.  Defines a 9x9 adjacency matrix representing a sample weighted graph.
2.  Calls `dijkstra()` with vertex `0` as the source.
3.  The output shows the shortest path cost from vertex 0 to every other vertex.

## Sample Output

```text
--- Dijkstra's Algorithm for Shortest Path ---

Vertex 	 Distance from Source
0 	 0
1 	 4
2 	 12
3 	 19
4 	 21
5 	 11
6 	 9
7 	 8
8 	 14
```
