#include<bits/stdc++.h>
using namespace std;
/*
    this algorithm is use to find the maximum sum of 
    given window length in arr[] where n is length and
    k is windows size 
*/
int sliding_win(int arr[], int n, int k)
{
    int crnt_win=0;
    
    for(int i=0;i<k;i++)
        crnt_win+=arr[i];

    int max_win = crnt_win;
    
    for(int i=k;i<n;i++)
        {
            max_win = max(max_win,crnt_win);
            crnt_win = (crnt_win-arr[i-k])+arr[i];
        }
    
    return max_win;
}

int main()
{
    int arr[] = {1,-2,4,5,7,-9,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = sliding_win(arr,n,2);
    cout<<ans<<endl;

    return 0;
}

