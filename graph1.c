#include <stdio.h>

int n;
int graph[10][10];
int visited[10];

/* DFS Function */
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 1; i <= n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

/* BFS Function */
void BFS(int start)
{
    int queue[10], front = 0, rear = 0;
    int i, v;

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 1; i <= n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start, choice;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    while (1)
    {
        printf("\nMENU");
        printf("\n1. DFS Traversal");
        printf("\n2. BFS Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
            return 0;

        printf("Enter starting city: ");
        scanf("%d", &start);

        for (i = 1; i <= n; i++)
            visited[i] = 0;

        switch (choice)
        {
            case 1:
                printf("Cities reachable using DFS: ");
                DFS(start);
                break;

            case 2:
                printf("Cities reachable using BFS: ");
                BFS(start);
                break;

            default:
                printf("Invalid choice");
        }
    }
}
