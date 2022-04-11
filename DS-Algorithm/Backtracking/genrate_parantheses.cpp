#include<bits\stdc++.h>
using namespace std;

// this algorithm is using defth first search DFS
// drow the tree and then try to fix all cases

void genrate(vector<string> &ans, string s,int open, int close,int n)
{
    if(open+close==2*n)
    {
        ans.push_back(s);
        return;
    }
    
    // adding open (
    if(open<n)
        genrate(ans,s+'(',open+1,close,n);
    
    // adding close )
    if(close<open)
        genrate(ans,s+')',open,close+1,n);
}
int main()
{
    vector<string> s;
    string tmp;
    int n=3;
    genrate(s,tmp,0,0,n);

    for(string i:s)
    {
        for(char c:i)
            cout<<c;
        cout<<endl;
    }

    return 0;
}