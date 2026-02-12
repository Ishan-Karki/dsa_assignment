#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// --- Graph Structure ---
typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

// --- Function Prototypes ---
void initGraph(Graph *g, int vertices);
void addEdge(Graph *g, int src, int dest);
void bfs(Graph *g, int startVertex);
void dfs(Graph *g, int startVertex);
void dfsRecursive(Graph *g, int vertex, int visited[]);

// --- Main Function ---
int main() {
    Graph g;
    
    // Create a graph with 5 vertices (0 to 4)
    initGraph(&g, 5);

    // Adding edges to create the following graph:
    // 0 -- 1
    // |    | \
    // 2 -- 3 -- 4
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);

    printf("--- Graph Traversal (Adjacency Matrix) ---\n\n");
    
    printf("Breadth First Search (starting from vertex 0):\n");
    bfs(&g, 0); // Expected: 0 1 2 3 4
    printf("\n\n");

    printf("Depth First Search (starting from vertex 0):\n");
    dfs(&g, 0); // Expected: 0 1 3 2 4 (or similar depending on edge order)
    printf("\n");

    return 0;
}

// --- Function Implementations ---

void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int src, int dest) {
    // Undirected graph: setup both [src][dest] and [dest][src]
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void bfs(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue start vertex and mark as visited
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Visit all adjacent vertices
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void dfsRecursive(Graph *g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsRecursive(g, i, visited);
        }
    }
}

void dfs(Graph *g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    dfsRecursive(g, startVertex, visited);
}
