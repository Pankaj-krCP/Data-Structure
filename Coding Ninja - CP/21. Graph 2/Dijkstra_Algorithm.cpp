#include <bits/stdc++.h>
using namespace std;

int getMinVertex(int *distance, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    { //getting min vertex from remaining unvisited nodes which has less distance value
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }

    return minVertex;
}

void dijkstras(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minVertex = getMinVertex(distance, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && edges[minVertex][j] != 0)
            {
                if (distance[j] > (distance[minVertex] + edges[minVertex][j]))
                { //better way exist to reach 'j' node from minVertex
                    distance[j] = (distance[minVertex] + edges[minVertex][j]);
                }
            }
        }
    }

    //distance array contains distance of each node from source i.e '0th vertex'
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    return;
}

int main()
{

    int n, e;
    cin >> n >> e;
    int **edges = new int *[n]();
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
    }

    for (int i = 0; i < e; i++)
    {
        int start, end, w;
        cin >> start >> end >> w;
        edges[start][end] = w;
        edges[end][start] = w;
    }

    dijkstras(edges, n);
    return 0;
}
