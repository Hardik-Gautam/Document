#include<bits/stdc++.h>
using namespace std;
/*
    Array size must be present in the array 
    such that 7
    ex:-> [1,3,2,4,6,5,7,3] n=7
*/


int floyd_cycle_det(int arr[],int n)
{
    int slow=arr[0];
    int fast=arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow!=fast);
    slow = arr[0];
    while (slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
    
    
}
int main()
{
    int arr[]={1,3,4,6,5,7,3};
    int n = 7;
    // cout<<floyd_cycle_det(arr,n);
    int a[]={1,2,3,4,5,6,7,8,9};
    
    for (int i = 0; i < 9; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
    
    return 0;
    

}