#include <bits/stdc++.h>
using namespace std;

class Edges
{

public:
    int src;
    int dest;
    int weight;
};

class compare
{
public:
    bool operator()(Edges const &a, Edges const &b)
    {
        return a.weight < b.weight;
    }
};

int findParent(int *parent, int vertex)
{

    if (parent[vertex] == vertex)
        return vertex;

    return findParent(parent, parent[vertex]);
}

int getOutput(Edges *input, int size, int *parent, int V, int A, int *count)
{

    int totalweight = 0;

    for (int i = 0; i < size; i++)
    {
        Edges e = input[i];

        int p1 = findParent(parent, e.src);
        int p2 = findParent(parent, e.dest);

        if (p1 != p2 && e.weight < A)
        {
            totalweight += e.weight;
            parent[p1] = p2;
        }
    }

    for (int i = 1; i <= V; i++)
    {

        if (parent[i] == i)
            (*count)++;
    }

    totalweight += ((*count) * A);

    return totalweight;
}

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        int V, E, A;
        cin >> V >> E >> A;

        Edges *input = new Edges[E];

        for (int i = 0; i < E; i++)
        {
            Edges e;
            cin >> e.src >> e.dest >> e.weight;
            input[i] = e;
        }

        sort(input, input + E, compare());

        int count = 0;

        int *parent = new int[V + 1];

        for (int i = 0; i <= V; i++)
        {
            parent[i] = i;
        }
        int output = getOutput(input, E, parent, V, A, &count);

        cout << "Case #" << c << ": " << output << " " << count << endl;
        c++;
    }

    return 0;
}
