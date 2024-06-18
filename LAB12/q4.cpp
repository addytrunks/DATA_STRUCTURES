// Program to implement Graph ADT using adjacency matrix

#include <stdio.h>
#include <stdlib.h>

class AdjacencyMatrix
{
    int V;
    int **adjMatrix;

public:
    AdjacencyMatrix(int V)
    {
        this->V = V;
        adjMatrix = (int **)malloc(V * sizeof(int *));
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = (int *)malloc(V * sizeof(int));
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void addEdge(int, int);
    void printGraph();
    int search(int, int);
    int deleteEdge(int, int);
};

int main(){
    int V, choice, u, v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    AdjacencyMatrix graph(V);

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
            printf("Adjacency Matrix Representation:\n");
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

// Method to add an edge to the graph: O(1)
void AdjacencyMatrix::addEdge(int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

// Method to print the graph: O(V^2)
void AdjacencyMatrix::printGraph()
{
    for (int i = 0; i < V; ++i)
    {
        printf("%d: ", i);
        for (int j = 0; j < V; ++j)
        {
            if (adjMatrix[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Method to search for an edge: O(1)
int AdjacencyMatrix::search(int u, int v)
{
    if (adjMatrix[u][v] == 1)
    {
        return 1;
    }
    return 0;
}

// Method to delete an edge: O(1)
int AdjacencyMatrix::deleteEdge(int u, int v)
{
    if (adjMatrix[u][v] == 1)
    {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        return 1;
    }
    return -1;
}

