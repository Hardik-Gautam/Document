#include<bits\stdc++.h>
using namespace std;

void addEdge(vector<int> v[], int edge, int vertex)
{
    v[edge].push_back(vertex);
    v[vertex].push_back(edge);
}

void normal_print(vector<int> v[],int size)
{
    for(int i = 0; i < size; i++ )
    {
        cout<<"Node "<<i<<": ";
        for(int &edge: v[i])
            cout<<edge<<" ";
        cout<<endl;
    }
}

void BFS_connected_graph(vector<int> v[], int size, int start)
{
    bool vertex[size];
    fill(vertex, vertex+size, false);

    queue<int> q;
    vertex[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        cout<<node<<" ";
        q.pop();

        for(int i = 0; i < size; i++)
            if(!vertex[i])
            {
                vertex[i] = true;
                q.push(i);
            }
    }
    
}

int main()
{
    int size = 6;
    vector<int> v[size];

    addEdge(v, 0, 1);
    addEdge(v, 0, 2);
    addEdge(v, 0, 3);
    addEdge(v, 1, 2);
    addEdge(v,4,5);
    normal_print(v, size);   
    cout<<endl;
    BFS_connected_graph(v, size, 3);
    return 0;
}