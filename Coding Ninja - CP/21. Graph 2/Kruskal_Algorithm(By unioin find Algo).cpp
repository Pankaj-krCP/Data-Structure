#include <bits/stdc++.h>
using namespace std;

//kruskal algorithm calculates minimum spanning tree of graph
//sort edges in axsending order
//take care of no cycle formation(union find algo)
//number of output edges = vertices - 1
//time complexity O()

struct Edge
{
    int v1;
    int v2;
    int w;
};

bool compare(Edge e1, Edge e2)
{
    return e1.w < e2.w; //sort according to weight
}

int getParent(int *parent, int v)
{
    if (v == parent[v])
    { //if parent of 2->1 ,1->0,0->0   call fun(arr,2) -> fun(arr,1) -> fun(arr,0) return  arr[v] = v
        return v;
    }

    return getParent(parent, parent[v]);
}

Edge *kruskal(Edge *edges, int n, int e)
{
    sort(edges, edges + e, compare);
    Edge *output = new Edge[n - 1];
    int count = 0; //to count edges = n-1
    int i = 0;     //to treverse all edges in input graph
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    while (count < (n - 1))
    {
        Edge currentEdge = edges[i];
        int srcParent = getParent(parent, currentEdge.v1);
        int dstParent = getParent(parent, currentEdge.v2);
        if (srcParent != dstParent)
        {
            output[count] = edges[i];
            parent[dstParent] = srcParent;
            count++;
        }
        i++;
    }
    return output;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *edges = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int src, dst, W;
        cin >> src >> dst >> W;
        edges[i].v1 = src;
        edges[i].v2 = dst;
        edges[i].w = W;
    }

    Edge *output = kruskal(edges, n, e);

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].v1 < output[i].v2)
        {
            cout << output[i].v1 << " " << output[i].v2 << " " << output[i].w << endl;
        }
        else
        {
            cout << output[i].v2 << " " << output[i].v1 << " " << output[i].w << endl;
        }
    }

    return 0;
}