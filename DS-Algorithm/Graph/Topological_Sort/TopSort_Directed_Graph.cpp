#include<bits\stdc++.h>
using namespace std;

class Directed_Graph
{
private:
    int size = 0;
    vector<int> v[1000];
    void TopoDFSsort(vector<int> v[], vector<bool> &vis, stack<int> &st, int node)
    {
        vis[node] = true;
        
        for(int i : v[node]){
            if(!vis[i]){
                TopoDFSsort(v,vis,st,i);
            }
        }
        st.push(node);
    }
    vector<int> Topological_sort_DFS()
    {
        vector<bool> vis(size,false);
        stack<int> st;
        for(int i = 0; i < size; i++){
            if(!vis[i])
            {
                TopoDFSsort(v, vis, st, i);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
public:
    Directed_Graph(int n){
        size = n;
    }
    void AddEdge(int u, int vr){
        v[u].push_back(vr);
    }
    void TopSort_Result()
    {
        vector<int> ans = Topological_sort_DFS();
        for(int i : ans)
            cout<<i<<" ";
    }
};

int main()
{
    Directed_Graph Graph(6);
    Graph.AddEdge(2,3);
    Graph.AddEdge(3,1);
    Graph.AddEdge(4,0);
    Graph.AddEdge(4,1);
    Graph.AddEdge(5,0);
    Graph.AddEdge(5,2);
    Graph.TopSort_Result();
}