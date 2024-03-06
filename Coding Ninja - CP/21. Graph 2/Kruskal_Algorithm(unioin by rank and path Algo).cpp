#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

Edge *kruskal(Edge *arr, int e, int n)
{
    Edge *output = new Edge[n - 1];
    int count = 0;
    int i = 0;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    while (count < (n - 1))
    {
        int src = arr[i].start;
        int dest = arr[i].end;
        int srcParent = parent[src];
        int destParent = parent[dest];
        if (srcParent != destParent)
        {
            output[count] = arr[i];
            count++;
            parent[dest] = srcParent;
        }
        i++;
    }
    return output;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *arr = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].weight;
    }
    sort(arr, arr + e, compare);
    Edge *output = kruskal(arr, e, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].start << " " << output[i].end << " " << output[i].weight << endl;
    }
    return 0;
}