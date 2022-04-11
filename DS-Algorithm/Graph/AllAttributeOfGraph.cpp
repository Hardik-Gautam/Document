#include<bits\stdc++.h>
using namespace  std;

class Graph
{
    private:
        int size = 0;
        vector<int> v[100000];

        bool DFS_Decet(vector<int> v[], vector<bool> &vis, vector<bool> &dfsVis, int source)
        {
            vis[source] = true;
            dfsVis[source] = true;

            for(int it: v[source])
            {
                if(!vis[it])
                {
                    if(DFS_Decet(v,vis, dfsVis, it))
                        return true;
                }
                else
                    if(dfsVis[it])
                        return true;
            }
            dfsVis[source] = false;
            return false;
        }
    public:
        Graph(int n ){
            size = n;
        }

        void DFS_Cycle(){

            vector<bool> vis(size, false);
            vector<bool> dfsVis(size,false);

            for(int i = 0; i < size; i++)
            {
                if(!vis[i])
                {
                    if(DFS_Decet(v, vis, dfsVis, i))
                        {
                            cout<<"Yes we got";
                            return ;
                        }
                }
            }
            cout<<"No ";
            return;
        }
};
class Undireceted_Graph
{
    
private:
    int size = 0;
    vector<int> Node[10000];
    void DFS_rec(vector<int> node[], vector<bool> &vis, int source)
    {
        vis[source]=true;
        cout<<source<<" ";
        for(int i: node[source])
            if(!vis[i])
                DFS_rec(node,vis,i);
    }

    bool DFScheckBipartite(vector<int> v[],vector<int> &col, int source)
    {
        if(col[source] == -1)
            col[source] = 1;

        for( int i : Node[source])
        {
            if(col[i] == -1)
                {
                    col[i] = 1 - col[source];
                    if(DFScheckBipartite(v,col,i))
                        return true;
                    
                }
            else
                if(col[i] == col[source])
                    return true;
        }
        return false;
    }
    
    bool BFScheckBipartite(vector<int> &col, int source)
    {
        queue<int> q;
        q.push(source);
        col[source] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for( int i : Node[node])
            {
                if(!col[i] == -1)
                {
                    col[i] = 1 - col[node];
                    q.push(i);
                }
                else
                    if(col[i]==col[node])
                        return true;
            }
        }
        return false;
    }
    
    bool BFS_Cycle(vector<bool> &vis, int source)
    {
        queue<pair<int,int>> q;
        q.push({source,-1});
        vis[source] =true;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
                q.pop();
        
            for( int it : Node[node])
            {
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push({it,node});
                }
                else
                    if(it != parent)
                    {
                        return true;
                    }
            }   
        }   
        return false;
    }
    
    bool DFS_Cycle(vector<bool> &vis, int source, int parent)
    {
        vis[source] = true;
        for(int it: Node[source])
            {
                if(!vis[it])
                {
                    if(DFS_Cycle(vis,it, source))
                        return true;
                    else
                        {
                            if(it != parent)
                                return true;
                        }
                }
            }
        return false;
    }


public:
    Undireceted_Graph(int a)
    {
        size = a;
    }

    void addEdge(int u, int v)
    {
        Node[u].push_back(v);
        Node[v].push_back(u);
    }

    void print()
    {
        for( int i =0;i<size; i++)
        {
            cout<<"Node "<<i<<": ";
            for(int it: Node[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    void BFS()
    {
        vector<bool> vis(size,false);
        for(int i = 0; i < size; i++)
        {
            if(!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty())
                {
                    int node = q.front();
                    cout<<node<<" ";
                    q.pop();

                    for(int it : Node[node])
                    if(!vis[it])
                        { 
                            vis[it] = true;
                            q.push(it);
                        }
                }
                
            }
        } 
    }

    void DFS()
    {
        vector<bool> vis(size,false);
        for( int i = 0; i < size; i++)
        {
            if(!vis[i])
                DFS_rec(Node, vis, i);
        }
    }

    void BFS_DecetCycle()
    {
        vector<bool> vis(size,false);
        for( int i = 0; i < size; i++)
            {
                if(BFS_Cycle(vis, i))
                    {
                        cout<<"Loop Deceted !";
                        return;
                    }
            }
            cout<<"Not Loop Deceted";
    }
    void DFS_DecetCycle()
    {
        vector<bool> vis(size, false);
        for(int i = 0; i < size; i++)
            if(!vis[i])
                if(DFS_Cycle(vis, i, -1))
                    {
                        cout<<"Loop Deceted !";
                        return;
                    }
        cout<<"Not Loop Deceted";
    }

    void BFS_Bipartite()
    {
        vector<int> col(size, -1);
        for(int i = 0 ;i<size;i++)
        {
            if(col[i] == -1)
            {
                if(BFScheckBipartite(col,i))
                    {
                        cout<<"This Graph is not Bipartite";
                        return ;
                    }    
            }
        }
        cout<<"This Graph is Bipartite";
    }
    
    void DFS_Bipartite()
    {
        vector<int> col(size, -1);

        for( int i =0 ; i< size; i++)
            {
                if(col[i] == -1)
                {
                    if(DFScheckBipartite(Node,col,i))
                        {
                            cout<<"This Graph is not Bipartite";
                            return;
                        }
                }
            }
        cout<<"This Graph is Bipartite";
    }
};

int main()
{
    Undireceted_Graph Graph(7);
    Graph.addEdge(0,1);
    Graph.addEdge(0,3);
    Graph.addEdge(1,2);
    Graph.addEdge(1,3);
    Graph.addEdge(2,4);
    Graph.addEdge(2,5);
    Graph.addEdge(3,4);
    Graph.addEdge(4,5);
    Graph.addEdge(4,6);
    Graph.addEdge(5,6);
    Graph.print();
    Graph.DFS();
    Graph.BFS();
    Graph.BFS_DecetCycle();
    Graph.DFS_DecetCycle();
    Graph.BFS_Bipartite();
    Graph.DFS_Bipartite();
    
    return 0;
}