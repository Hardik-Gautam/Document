#include<bits/stdc++.h>
using namespace std;

/*
    this method is find the last occurence of 
    given item in array 
    array must be sorted for it

*/
// brute force approch 
int last_occ_brute_fr(int arr[], int n, int item)
{
    for(int i=0;i<n;i++)
    if(arr[i]==item && arr[i+1]!=item)
        return i+1;
    return -1;
}

// efecient solution 
int last_occ_bin_seah(int arr[], int n, int item)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int m = (low+high)/2;
        if(arr[m]>item)
            high = m+1;
        else
            if(arr[m]<item)
                low = m+1;
        else
            {
                if(m!=n-1 || arr[m]!=arr[m+1])
                    return m;
                low = m+1;
            }
    }
    return 1;
}

int main()
{
    int arr[] = {1,2,3,3,4,5,5,5,8};
    int n =  sizeof(arr)/sizeof(arr[0]);
    // cout<<last_occ_brute_fr(arr,n,1);
    cout<<last_occ_bin_seah(arr,n,5);
    return 0;
}
