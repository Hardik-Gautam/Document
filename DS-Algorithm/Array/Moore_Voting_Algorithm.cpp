#include<bits/stdc++.h>
using namespace std;

/* 
    Boyer Moore algorithm is use to find majority elemenet in 
    given array by O(n) time complexity and O(1) space complexity
    Example : [1,2,3,2,4,2]
    Answere : 2  
*/
int by_sort(int arr[],int n)
{
    sort(arr,arr+n);
    // { 1, 1, 1, 1, 2, 3, 4 }
    int count=1;
    int ind=0;
    int rs=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[ind])
            count++;
        else
        {
            rs = max(rs,count);
            if(rs>n/2)
                return arr[ind];
            ind=i;
            count=1;
        }
        
    }
    return -1;
}

int Moore_Algo(int arr[], int n)
{
    // [1,2,3,2,4,7,7,5,2]
    int count=1;
    int indx=0;
    for(int i=0;i<n;i++)
    {
        
        if(arr[i]==indx)
            count++;
        else
            count--;

        if(count==0)
        {
            indx=arr[i];
            count=1;
        }
    }

    count=0;
    
    for(int i=0;i<n;i++)
        if(arr[i]==indx)
            count++;
    
    if(count>n/2)
        return indx;
    
    return -1;
}


int main()
{
    int arr1[]={ 1, 1, 1, 3, 4 ,2};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    cout<<"Size of array : "<<size<<endl;
    cout<<"Majority of Array Item : "<<Moore_Algo(arr1,size);
   
    return 0;
}