#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> getConnectedComponents(int **edges, int n, int start, bool *visited)
{
    queue<int> vertices;
    vector<int> ans;
    vertices.push(start);
    visited[start] = true;

    while (!vertices.empty())
    {
        int current = vertices.front();
        ans.push_back(current);
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
    return ans;
}

vector<vector<int>> getans(int **edges, int n)
{
    bool *visited = new bool[n];
    vector<vector<int>> components;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans = getConnectedComponents(edges, n, i, visited);
            components.push_back(ans);
        }
    }
    return components;
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

    vector<vector<int>> components = getans(edges, n);
    for (int i = 0; i < components.size(); i++)
    {
        sort(components[i].begin(), components[i].end()); //sorting individual vectors
        for (int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
#include <vector>

vector<int> getComponent(int **edges, bool *visited, int n, int start)
{
    vector<int> ans;
    queue<int> pending;
    pending.push(start);
    visited[start] = true;
    while (!pending.empty())
    {
        int current = pending.front();
        pending.pop();
        ans.push_back(current);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && i != start && edges[current][i] == 1)
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
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

    vector<vector<int>> components;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component = getComponent(edges, visited, n, i);
            components.push_back(component);
        }
    }
    if (components.size() != 0)
    {
        for (int i = 0; i < components.size(); i++)
        {
            sort(components[i].begin(), components[i].end());
            for (int j = 0; j < components[i].size(); j++)
            {
                cout << components[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No components returned" << endl;
    }
    return 0;
}
*/