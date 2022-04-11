#include<bits\stdc++.h>
using namespace std;
void swap(int arr[],int n,int m)
{
    int temp = arr[n];
    arr[n] = arr[m];
    arr[m] = temp;
}

/*
    this sorting algoritm is used to sort
    three elements in array basically this algo is used
    modifyed haore partition of the qucik sort
*/
void dnfsort(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr,low,mid);
            low++;
            mid++;
        }
        else
            if(arr[mid]==2)
            {
                swap(arr,mid,high);
                high--;
            }
        else
            {
                mid++;
            }
    }
}
int main()
{
    int arr[] = {0,1,1,0,2,0,2,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);

    dnfsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}