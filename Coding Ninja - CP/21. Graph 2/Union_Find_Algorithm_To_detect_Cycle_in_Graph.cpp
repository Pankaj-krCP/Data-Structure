#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int src;
    int des;
};

int findParent(int * parent,int v){
     if(parent[v] == v){ //if parent = vertex (thats the original parent of all )
        return v;
    }
    return findParent(parent,parent[v]); 
}

void findCycle(Graph * edges,int n,int e,int * parent){
    int count = 0;
    while(e--){
        int src = edges[count].src;
        int des = edges[count].des;
        int srcParent = findParent(parent,src);
        int destParent = findParent(parent,des);
        if(srcParent == destParent){
            cout<<"graph contain cycle"<<endl;
            return;
        }else{
            parent[des] = src;
        }
        count++;
    }
    cout<<"graph doesnot contain cycle"<<endl;
}

int main(){
    int n,e;
    cin>>n>>e;

    Graph *edges = new Graph[e];

    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        edges[i].src = v1;
        edges[i].des = v2;
    }

    int * parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    findCycle(edges,n,e,parent);

    return 0;
}