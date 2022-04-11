#include<bits\stdc++.h>
using namespace std;

void permut(vector<int> input, vector<vector<int>> &ans, int i)
{
    if(i==input.size())
    {
        ans.push_back(input);
        return;
    }
    for(int it=i;it<input.size();it++)
    {
        swap(input[i],input[it]);
        permut(input, ans, i+1);
        swap(input[i],input[it]);
    }
}

int main()
{
    vector<int> in;
    in.push_back(1);
    in.push_back(2);
    in.push_back(3);
    vector<vector<int>> ans;
    permut(in,ans,0);
    for(vector<int> i:ans)
        {
            for(int j:i)
            cout<<j<<" ";
            cout<<endl;
        }
    return 0;
}