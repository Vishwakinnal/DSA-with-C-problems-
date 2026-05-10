#include <stdio.h>

int n;
int graph[10][10];
int visited[10];

/* DFS Function */
void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 1; i <= n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

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

    printf("Enter starting city: ");
    scanf("%d", &start);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("Cities reachable using DFS: ");
    dfs(start);

    return 0;
}
