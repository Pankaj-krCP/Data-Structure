#include <iostream>
#include <queue>
using namespace std;

bool getansBFS(int **edges, int n, int start, int end)
{
    if (start == end)
    {
        return true;
    }
    if (edges[start][end] == 1)
    {
        return true;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == current)
            {
                continue;
            }

            if (edges[current][i] == 1 && !visited[i])
            {
                if (i == end)
                {
                    return true;
                }

                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}

// bool getansDFS(int** edges,int n,int start,int end,bool* visited){
//     if(start == end){
//         return true;
//     }

//     for(int i=0;i<n;i++){
//         if(!visited[i] && i != start && edges[start][i] == 1){
//             visited[i] = true;
//             if(getansDFS(edges,n,i,end,visited)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

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

    int start, end;
    cin >> start >> end;

    //BFS IMPLEMENTATION
    bool ans = getansBFS(edges, n, start, end);

    //     DFS IMPLEMENTATION
    //     bool* visited = new bool[n];
    //     for(int i=0;i<n;i++){
    //         visited[i] = false;
    //     }
    //     visited[start] = true;
    //     bool ans = getansDFS(edges,n,start,end,visited);

    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
