
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int V;
    struct Node *head[100];
};

// Create a new linked list node
struct Node *createNode(int v)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// Create graph
struct Graph *createGraph(int V)
{
    struct Graph *graph =
        (struct Graph *)malloc(sizeof(struct Graph));

    graph->V = V;

    for (int i = 0; i < V; i++)
    {
        graph->head[i] = NULL;
    }

    return graph;
}

// Add an undirected edge
void addEdge(struct Graph *graph, int src, int dest)
{

    // src -> dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;

    // dest -> src
    newNode = createNode(src);
    newNode->next = graph->head[dest];
    graph->head[dest] = newNode;
}

// Display adjacency list
void display(struct Graph *graph)
{

    for (int i = 0; i < graph->V; i++)
    {

        struct Node *temp = graph->head[i];

        printf("%d", i);

        while (temp != NULL)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }

        printf(" -> NULL\n");
    }
}

int main()
{

    int V = 4;

    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    display(graph);

    return 0;
}
