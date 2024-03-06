#include <bits/stdc++.h>
using namespace std;

void getcount(int **edges, int n, int start, bool *visited)
{
    queue<int> vertices;
    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty())
    {
        int current = vertices.front();
        vertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[current][i] == 1 && i != current)
            {
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
    return;
}

int DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++; //everytime function is called we get one connected component
            getcount(edges, n, i, visited);
        }
    }

    return count;
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

    cout << DFS(edges, n) << endl;
    return 0;
}
