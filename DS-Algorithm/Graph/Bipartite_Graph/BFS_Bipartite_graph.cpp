#include<bits/stdc++.h>
using namespace std;

class Bipartite_Graph
{
private:
    int size = 0;
    vector<int> Node[1000];
public:
    Bipartite_Graph(int n)
    {
        size = n;
    }

    void addEdge(int u, int v)
    {
        Node[u].push_back(v);
        Node[v].push_back(u);
    }

    bool isBiparite()
    {
        vector<int> color(size,-1);

        for(int i = 0; i < size; i++)
        {
            if(color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    // cout<<node<<" ";
                    q.pop();
                    for(int it: Node[node])
                    {
                        if(color[it] == -1)
                        {
                            color[it] = 1 - color[node];
                            q.push(it);
                        }
                        else
                        {
                            if(color[it] == color[node])
                                return false;
                        }   
                    }
                }
                
            }
        }
        return true;
    }
    void normalPrint()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<"Node "<<i<<": ";
            for(int it:Node[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    void Ans()
    {
        if(isBiparite())
            cout<<"This Graph is Bipartite";
        else
            cout<<"This Graph is not Bipartite";
    }
};



int main()
{
    Bipartite_Graph BGraph(7);
    BGraph.addEdge(0,1);
    BGraph.addEdge(1,2);
    BGraph.addEdge(1,3);
    BGraph.addEdge(2,4);
    BGraph.addEdge(2,5);
    BGraph.addEdge(2,6);
    BGraph.addEdge(3,4);
    BGraph.addEdge(4,5);

    // BGraph.normalPrint();
    BGraph.isBiparite();
    BGraph.Ans();
    return 0;
}