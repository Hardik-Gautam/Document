#include<bits\stdc++.h>
using namespace std;

void SubSet(vector<vector<int>> &arr,vector<int> output, vector<int> input, int n)
{
    if(n==input.size())
    {
        arr.push_back(output);
        return ;
    }
    // we will take item 
    SubSet(arr,output,input,n+1);
    
    // we will not take item
    output.push_back(input[n]);
    SubSet(arr,output,input,n+1);
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // vector<vector<int>> ans;
    // vector<int> output;
    // SubSet(ans,output,v,0);
    // for(vector<int> i:ans)
    //     {
    //         for(int j:i)
    //             cout<<j<<" ";
    //         cout<<endl;
    //     }
    cout<<101%7;
    return 0;
}