#include<bits\stdc++.h>
using namespace std;
 
void addEdge(vector<int> v[], int edge, int vertex)
{
    v[edge].push_back(vertex);
    v[vertex].push_back(edge);
}

void normal_print(vector<int> v[], int size)
{
    for( int i = 0 ; i < size; i++ )
    {
        cout<<"Node "<<i<<": ";
        for(int &item: v[i])
            cout<<item<<" ";
        cout<<endl; 
    }
}

void DFSres(vector<int> v[], int source, bool visited[])
{
    visited[source] = true;
    cout<<source<<" ";

    for(int const &edge: v[source])
        if( !visited[edge] )
            DFSres(v, edge, visited);
}

void DFS(vector<int> v[], int size)
{
    bool visited[size];
    fill(visited, visited + size,  false);

    for( int i = 0; i < size; i++ )
    if( !visited[i] )
            DFSres(v, i, visited);
        
}

int main()
{
    int size = 4;
    vector<int> v[size];
    addEdge(v,0,1);
    addEdge(v,0,2);
    addEdge(v,0,3);
    addEdge(v,1,2);

    // normal_print(v, size);

    DFS(v, size);

    return 0;
}