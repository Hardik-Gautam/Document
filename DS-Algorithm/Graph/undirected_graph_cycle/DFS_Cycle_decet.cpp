#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> vr[], int u, int v)
{
    vr[u].push_back(v);
    vr[v].push_back(u);
}

bool dfs_cycleRec(vector<int> v[], vector<bool> &vis, int node, int parent)
{
    vis[node] = true;
    
    for(int it : v[node])
    {
        if(!vis[it])
        {
            if(dfs_cycleRec(v,vis,it,node))
                return true;
        }
        else
        {
            if(it != parent)
                return true;
        }
    }
    return false;
}

void dfs_cycle(vector<int> v[], int size)
{
    vector<bool> vis(size,false);
    for(int i = 0 ; i < size;i++)
    if(!vis[i])
    {
        if(dfs_cycleRec(v,vis,i,-1))
            {
                cout<<"loop";
                return;
            }
    }
    cout<<"no loop";
    return;
}

int main()
{
    int size = 5;
    vector<int> v[size];
    addEdge(v,0,1);
    addEdge(v,0,2);
    addEdge(v,0,3);
    // addEdge(v,1,2);
    
    dfs_cycle(v,size);
    return 0;
}