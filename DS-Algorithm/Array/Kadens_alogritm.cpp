#include<bits/stdc++.h>
using namespace std;
/*
    this algorithm is use to find maximun sub array in 
    given array 
*/
int maxSubArray(int arr[], int n)
{
    int crente=0;
    int ans=arr[0];
    for(int i=0;i<n;i++)
    {
        crente += arr[i];
        ans = max(ans,crente);
        crente = max(crente,0);
    }
    return ans;
}

int main()
{
    int arr[] = {1,-2,4,5,7,-9,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = maxSubArray(arr,n);
    cout<<ans<<endl;
    return 0;
}