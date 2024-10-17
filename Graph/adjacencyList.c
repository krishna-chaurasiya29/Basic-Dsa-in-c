#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


typedef struct Graph // Define the structure for a graph
{
    int Vertices;
    Node **adjLists;
} Graph;

Node *createNode(int data) // Function to create a new node
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph(int Vertices) // Function to create a graph  
{
Graph* graph = (Graph*) malloc(sizeof(Graph));
    if (!graph)
    {
        printf("Memory error\n");
        return NULL;
    }
    graph->Vertices = Vertices;
    graph->adjLists = (Node **)malloc(Vertices * sizeof(Node *));
    for (int i = 0; i < Vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest) // Function to add an edge to
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
void printGraph(Graph *graph) // Function to print the graph
{
    for (int i = 0; i < graph->Vertices; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("Adjacency list of vertex: %d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int Vertices = 5;
    Graph *graph = createGraph(Vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}

/*
Output:-

Adjacency list of vertex: 0: 4 -> 1 ->
Adjacency list of vertex: 1: 4 -> 3 -> 2 ->
Adjacency list of vertex: 2: 3 ->
Adjacency list of vertex: 3: 4 ->
Adjacency list of vertex: 4:
*/