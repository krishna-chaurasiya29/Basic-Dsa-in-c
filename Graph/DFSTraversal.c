// DFS algorithm in C
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node *next;
};
struct node *createnode(int v);
struct graph
{
    int numvertices;
    int *visited;
    struct node **adjlists;
};
// Create a node
struct node *createnode(int v)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

// Create graph
struct graph *creategraph(int vertices)
{
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numvertices = vertices;

    graph->adjlists = malloc(vertices * sizeof(struct node *));

    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjlists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge
void addEdge(struct graph *graph, int src, int dest)
{
    struct node *newnode = createnode(dest);
    newnode->next = graph->adjlists[src];
    graph->adjlists[src] = newnode;
    newnode = createnode(src);
    newnode->next = graph->adjlists[dest];
    graph->adjlists[dest] = newnode;
}

// Print the graph
void printgraph(struct graph *graph)
{
    int v;
    for (v = 0; v < graph->numvertices; v++)
    {
        struct node *temp = graph->adjlists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFS(struct graph *graph, int vertex)
{
    struct node *adjlist = graph->adjlists[vertex];
    struct node *temp = adjlist;

    graph->visited[vertex] = 1;
    printf("\n visited %d \n", vertex);
    while (temp != NULL)
    {
        int connectedvertex = temp->vertex;
        if (graph->visited[connectedvertex] == 0)
        {
            DFS(graph, connectedvertex);
        }
        temp = temp->next;
    }
}


int main()
{
    struct graph *graph = creategraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printgraph(graph);

    DFS(graph, 2);
}