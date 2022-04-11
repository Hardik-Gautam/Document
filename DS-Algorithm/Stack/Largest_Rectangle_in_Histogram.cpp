#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class LRHistogram {

private:
    
    vector<int> nextSmallerItem(vector<int> &arr)
    {
        int n = arr.size();
        
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--)
        {
                    
            while(s.top()!=-1 && arr[s.top()] >= arr[i])
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
       return ans; 
    }

private:    
    vector<int> prevSmallerItem(vector<int> &arr)
    {
        int n = arr.size();
        
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        
        for(int i = 0 ; i < n ; i++)
        {
           
            while(s.top()!=-1 && arr[s.top()] >= arr[i])
                s.pop();
            
            ans[i] = s.top();
            s.push(i);
        }
       return ans; 
    }

public:    
    int largestRectangleArea(vector<int>& h) {
        
        vector<int> next = nextSmallerItem(h);
        vector<int> prev = prevSmallerItem(h);
        
        int n = h.size();
        int ans=0;

        for(int i = 0; i < n; i++)
        {
            if(next[i]==-1)
                next[i] = n;
            
            ans = max(ans, (h[i] * (next[i]-prev[i]-1)) );
        }
        
        return ans;
    }
};
int main()
{
    vector<int> v;
    // v = {2,1,5,6,2,3};
    v = {2,1};
    // v = {1,1};
    LRHistogram object;
    
    int ans = object.largestRectangleArea(v);
    cout<<ans<<endl;
    
    return 0;
}