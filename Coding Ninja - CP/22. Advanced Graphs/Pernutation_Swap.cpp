/*
Intuition :
get connected components among M pairs (M edges)

we can change P -> Q  if values present at indexes in P and Q can be swapped if they are inside same connected component
(connected component gives indexes) 

make two sets SP and SQ (insert values of index got from componensts index in SP and SQ)

check if two sets have same values then they can be swapped easily one another else cannot be swapped (hence anwer NO)
make graph for M pairs

*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<iterator>
using namespace std;
void dfs(vector<int>*edges, int start, bool*visited, unordered_set<int>*component)
{
    if(visited[start])
    {
        return;
    }
    visited[start]=true;
    component->insert(start);
    for(vector<int>::iterator it=edges[start].begin(); it!=edges[start].end(); it++)
    {
        if(!visited[*it])
        {
            dfs(edges, *it, visited, component);
        }
    }
}
unordered_set<unordered_set<int>*>* getComponents(vector<int>*edges, int n)
{
    bool *visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    unordered_set<unordered_set<int>*>*output=new unordered_set<unordered_set<int>*>();
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            unordered_set<int>*component=new unordered_set<int>();
            dfs(edges, i, visited, component);
            output->insert(component);
        }
    }
    return output;
}
int main()
{
    int t;//test cases
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        int *p=new int [n];
        int *q=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>q[i];
        }

        //graph initiated
        vector<int>*edges=new vector<int>[n];
        for(int i=0; i<m; i++)
        {
            int a, b;
            cin>>a>>b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }
        //adjacency list completed.
        unordered_set<unordered_set<int>*>* components=getComponents(edges, n);

        unordered_set<unordered_set<int>*>::iterator it1=components->begin();
        bool flag=true;
        while(it1!=components->end())
        {
            unordered_set<int>*component=*it1;
            unordered_set<int>::iterator it2=component->begin();
            unordered_set<int>p_index_set;
            unordered_set<int>q_index_set;
            while(it2!=component->end())
            {
                p_index_set.insert(p[*it2]);
                q_index_set.insert(q[*it2]);
                it2++;
            }
            if(p_index_set!=q_index_set)
            {
                flag=false;
            }
            it1++;
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}