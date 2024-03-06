#include <iostream>
#include <queue>
using namespace std;

void printBFS(bool **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        visited[currentVertex];
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
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

int main()
{
    int n, e; // number of verte and edges
    cin >> n >> e;

    bool **edges = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }

    printBFS(edges, n, 0);

    return 0;
}