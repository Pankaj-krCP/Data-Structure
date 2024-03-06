//For Disconnected Graph ( It works for connected graph as well )

#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        cout << currentVertex << " ";
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (currentVertex == i)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    BFS(edges, n);
    return 0;
}
