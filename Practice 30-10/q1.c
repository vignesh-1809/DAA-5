#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1)
        printf("\nQueue is full");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nQueue is empty");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph {
    Node** adjLists;
    int* visited;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (Node*)malloc(numVertices * sizeof(Node));
    graph->visited = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void bfs(Graph* graph, int startVertex) {
    Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->value;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void dfs(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->value;
        if (graph->visited[adjVertex] == 0)
            dfs(graph, adjVertex);
        adjList = adjList->next;
    }
}

int main() {
    int numVertices = 6;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 5);

    printf("BFS starting from vertex 0: ");
    bfs(graph, 0);
    printf("\n");
     printf("BFS starting from vertex 1: ");
     bfs(graph, 1); 
     bfs(graph,2);
     bfs(graph, 3); 
     bfs(graph,4);
     bfs(graph, 5);
     printf("\n");
    
     
     printf("BFS starting from vertex 2: ");
     bfs(graph, 2); 
     bfs(graph, 3); 
     bfs(graph,4);
     bfs(graph, 5);
      printf("\n");
      
       printf("BFS starting from vertex 3: ");
     bfs(graph, 3); 
     bfs(graph,4);
     bfs(graph, 5);
      printf("\n");
      
       printf("BFS starting from vertex 4: ");
     bfs(graph,4);
     bfs(graph, 5);
      printf("\n");
     
      printf("BFS starting from vertex 5: ");
     bfs(graph, 5);
      printf("\n");
    
    printf("\nDFS starting from vertex 0: ");
     dfs(graph, 0);
     dfs(graph,1);
     dfs(graph, 2);
     dfs(graph,3);
     dfs(graph, 4);
     dfs(graph,5);
     
     printf("\nDFS starting from vertex 1: ");
     dfs(graph,1);
     dfs(graph, 2);
     dfs(graph,3);
     dfs(graph, 4);
     dfs(graph,5);
     
     
      printf("\nDFS starting from vertex 2: ");
     dfs(graph, 2);
     dfs(graph,3);
     dfs(graph, 4);
     dfs(graph,5);
     
     
      printf("\nDFS starting from vertex 3: ");
     dfs(graph,3);
     dfs(graph, 4);
     dfs(graph,5);
     
      printf("\nDFS starting from vertex 4: ");
     dfs(graph, 4);
     dfs(graph,5);
     
     
      printf("\nDFS starting from vertex 5: ");
     dfs(graph,5);
     
     
    for (int i = 0; i < numVertices; i++) {
        if (graph->visited[i] == 0)
            dfs(graph, i);
    }

    return 0;
}
