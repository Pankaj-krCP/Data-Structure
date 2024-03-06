#include <bits/stdc++.h>
using namespace std;

void print(bool **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

int main()
{
    int n, e;
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    print(edges, n, 0, visited);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    delete[] visited;
    return 0;
}