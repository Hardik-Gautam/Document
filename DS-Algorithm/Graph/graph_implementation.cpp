#include<bits\stdc++.h>
using namespace std;

void addEdge_for_undirected(vector<int> adj[], int u, int v)
{
    // this is for undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addEdge_for_directed(vector<int> adj[], int u, int v)
{
    // this is for directed graph
    adj[v].push_back(u);
}

void addEdge_for_weighted(vector<pair<int,int>> adj[], int u, int v, int wt)
{
    // this is for undirected weighted graph
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

void printgraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout<<"Node "<<i<<": ";
        for(int x: adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
    
}

int main()
{
    int v=4;
    vector<int> adj[v];
    addEdge_for_undirected(adj,0,1);
    addEdge_for_undirected(adj,0,2);
    addEdge_for_undirected(adj,1,2);
    addEdge_for_undirected(adj,1,3);
    printgraph(adj,v);
   
    // [1][2]
    // [0][2][3]
    // [0][1]
    // [1]

    return 0;
}