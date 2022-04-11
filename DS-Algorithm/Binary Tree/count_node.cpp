#include<bits\stdc++.h>
using namespace std;

void addEdge(vector<int> v[], int s, int e)
{
    v[s].push_back(e);
    v[e].push_back(s);
}

void BFS(vector<int> v[], int size)
{
    vector<bool> visited(size,false);

    for(int i = 0; i < size; i++)
    {

        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                cout<< node <<" ";

                for(int index: v[i])
                if(!visited[index])
                {
                    
                    q.push(index);
                    visited[index] = true;
                }
                
            }
            
        
        }
        cout<<endl;
    }
}

void dfsres(vector<int> &v, vector<bool> &visited, int source)
{
    cout<<source<<" ";
    visited[source] = true;

    for(int i : v)
    {
        if(!visited[i])
            dfsres(v, visited, i);
    }
}

void dfs(vector<int> v[], int size)
{
    vector<bool> visited(size,false);
    
    for(int i = 0; i < size; i++)
    {
        if(!visited[i])
            dfsres(v[i], visited, i);
    }

}

int main()
{
    int n = 6;
    vector<int> v[n];

    addEdge(v,0,1);
    addEdge(v,0,2);
    addEdge(v,0,3);
    addEdge(v,1,2);
    addEdge(v,4,5);

    // BFS(v,n);
    // cout<<endl;
    // dfs(v,n);
    
    if( 1<2 and 2>1)
        cout<<1;
    
    return 0;
}