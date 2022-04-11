#include<bits\stdc++.h>
using namespace std;


void addEdge(vector<int> Node[], int edge, int vertex)
{
    Node[edge].push_back(vertex);
    Node[vertex].push_back(edge);
}

void BFS_Cycle(vector<int> v[], int size)
{
    vector<bool> visited(size,false);

    for(int i = 0; i < size; i++)
    {

        if(!visited[i])
        {
            queue<pair<int,int>> q;
            visited[i] = true;
            q.push({i,-1}); // parent = -1;

            while (!q.empty())
            {
                int node  = q.front().first;
                int parent = q.front().second;

                q.pop();
                cout<<"Node: "<<node<<" Parent: "<<parent<<endl;
                
                for(int it: v[node]) // v[node] this is importatent line 
                {
                    if(!visited[it])
                    {
                        visited[it] = true;
                        q.push({it,node});
                    }
                    else
                        if(it != parent)
                        {
                            cout<<"loop exist";
                            return ;
                        }
                }
            }
            
        }
    }
    cout<<"loop not exist";
    return ;
}



int main()
{
    int size = 7;
    vector<int> v[size];

    addEdge(v,0,1);
    addEdge(v,1,2);
    addEdge(v,1,3);
    addEdge(v,2,4);
    addEdge(v,2,6);
    addEdge(v,4,5);

    // addEdge(v,0,1);
    // addEdge(v,0,2);
    // addEdge(v,0,3);
    // addEdge(v,2,3);

    BFS_Cycle(v,size);
    
    return 0;
}