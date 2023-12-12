#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjacencyList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize adjacency list
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Add edge from dest to src (since the graph is undirected)
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Breadth-First Search
void bfs(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    // Create a queue for BFS
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = -1, rear = -1;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front != rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Explore adjacent vertices
        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }

    printf("\n");

    // Free allocated memory
    free(visited);
    free(queue);
}

// Depth-First Search (helper function)
void dfsHelper(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            dfsHelper(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Depth-First Search
void dfs(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    printf("DFS starting from vertex %d: ", startVertex);
    dfsHelper(graph, startVertex, visited);
    printf("\n");

    // Free allocated memory
    free(visited);
}

int main() {
    // Create a sample graph
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Perform BFS starting from vertex 0
    bfs(graph, 0);

    // Perform DFS starting from vertex 0
    dfs(graph, 0);

    // Free allocated memory for the graph
    free(graph->adjacencyList);
    free(graph);

    return 0;
}
