#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* weight,int n,bool* visited){//getting min vertex from remaining
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}


void prims(int** edges,int n){
    bool* visited = new bool[n]();
    int* weight = new int[n];
    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    
    int* parent = new int[n];
    parent[0] = -1;
    
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(weight,n,visited);
        visited[minVertex] = true;
        
        //explore adjacent of minVertex
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minVertex][j] != 0){
                if(weight[j] > edges[minVertex][j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }else{
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    
    return ;
}

int main()
{
  	
    int n,e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int start,end,w;
        cin >> start >> end >> w;
        edges[start][end] = w;
        edges[end][start] = w;
    }
    
    prims(edges,n);

  return 0;
}
