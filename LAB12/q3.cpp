// Program to implement Graph ADT using adjacency list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

class AdjacencyList
{
    int V;
    // Array of linked lists
    struct Node **adjList;

public:
    AdjacencyList(int V)
    {
        this->V = V;
        adjList = (struct Node **)malloc(V * sizeof(struct Node *));
        for (int i = 0; i < V; ++i)
        {
            adjList[i] = NULL;
        }
    }
    void addEdge(int, int);
    void printGraph();
    int search(int, int);
    int deleteEdge(int, int);
};

int main()
{
    int V, choice, u, v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    AdjacencyList graph(V);

    while (1)
    {
        printf("\n1. Add Edge\n2. Print Graph\n3. Delete\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the vertices (u v) to add edge: ");
            scanf("%d %d", &u, &v);
            if (u >= 0 && u < V && v >= 0 && v < V)
            {
                graph.addEdge(u, v);
                printf("Edge added successfully!\n");
            }
            else
            {
                printf("Invalid vertices! Please enter vertices within range 0 to %d\n", V - 1);
            }
            break;
        case 2:
            printf("Adjacency List Representation:\n");
            graph.printGraph();
            break;
        case 3:
            printf("Enter the vertices (u v) to delete edge: ");
            scanf("%d %d", &u, &v);
            if (u >= 0 && u < V && v >= 0 && v < V)
            {
                if (graph.deleteEdge(u, v) == -1)
                {
                    printf("Edge not found!\n");
                }
                else
                {
                    printf("Edge deleted successfully!\n");
                }
            }
            else
            {
                printf("Invalid vertices! Please enter vertices within range 0 to %d\n", V - 1);
            }
            break;
        case 4:
            printf("Enter the vertices (u v) to search edge: ");
            scanf("%d %d", &u, &v);
            if (u >= 0 && u < V && v >= 0 && v < V)
            {
               if(graph.search(u, v) == 1)
               {
                   printf("Edge found!\n");
               }
               else
               {
                   printf("Edge not found!\n");
               }
            }
            else
            {
                printf("Invalid vertices! Please enter vertices within range 0 to %d\n", V - 1);
            }
            break;
          case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

// Method to add an edge to an undirected graph: O(1)
void AdjacencyList::addEdge(int src, int dest)
{
    // Add edge from u to v
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge from v to u
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Method to print the graph: O(V + E)
void AdjacencyList::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        struct Node *temp = adjList[v];
        printf("Vertex %d --> ", v);
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Method to search for an edge in the graph: O(V)
int AdjacencyList::search(int src, int dest)
{
    struct Node *temp = adjList[src];
    while (temp && temp->vertex != dest)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return 0;
    }
    return 1;
}

// Method to delete an edge from the graph: O(V)
int AdjacencyList::deleteEdge(int src, int dest)
{
    struct Node *temp = adjList[src];
    struct Node *prev = NULL;
    while (temp && temp->vertex != dest)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return -1;
    }
    if (prev == NULL)
    {
        adjList[src] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);

    temp = adjList[dest];
    prev = NULL;
    while (temp && temp->vertex != src)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        adjList[dest] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    return 1;
}