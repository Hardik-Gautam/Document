#include<bits/stdc++.h>
using namespace std;

/*
    This solution is for sorted array 
    to find item first occurence index in array

*/


// Brute Force Approch 
int first_occ_brute_force(int arr[], int n, int item)
{
    for(int i=0;i<n;i++)
        if(arr[i]==item) 
            return i;
    return -1;
}

// Efecient Solution
// by using binary search algorithm
int first_occ_bin_sech(int arr[], int n, int item)
{
    // [1,2,3,5,5,8] = 6
    // item is 5
    int low=0;
    int high = n-1; // 5
    while(low<=high)
    {
        int m = (low+high)/2; // 3
        if(arr[m] > item)
            high = m-1; // 3
        else 
            if( arr[m] < item)
                low = m+1; // 3
        else
            {
                if(m==0 || arr[m-1]!=arr[m])
                    return m;
                high = m-1; // 3
            }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,5,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<first_occ_bin_sech(arr,n,5);
    return 0;
}