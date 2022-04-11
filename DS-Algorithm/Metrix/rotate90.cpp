#include"bits\stdc++.h"
using namespace std;
void print_boundry(int arr[4][4],int r,int c)
{
    for(int i=0;i<c;i++)
    cout<<arr[0][i]<<" ";
    cout<<endl;
    for(int i=0;i<r;i++)
    cout<<arr[i][c-1]<<" ";
    cout<<endl;
    for(int i=0;i<c;i++)
    cout<<arr[r-1][i]<<" ";
    cout<<endl;
    for(int i=r-1;i>=0;i--)
    cout<<arr[i][0]<<" ";
    cout<<endl;
}
void print_transpos_metrix(int arr[4][4],int r,int c)
{
    for(int i=0;i<r;i++)
        for(int j=i+1;j<c;j++)
            swap(arr[i][j],arr[j][i]);
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
void rotate_90_metrix(int arr[4][4],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=i+1;j<c;j++)
            swap(arr[i][j],arr[j][i]);
    }
    for(int i=0;i<r/2;i++)
    {
        for(int j=0;j<c;j++)
            swap(arr[i][j],arr[r-1-i][j]);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
void print_metrix_in_spirle(int arr[4][4],int r,int c)
{
    int top = 0;
    int right = c-1;
    int bottom = r-1;
    int left = 0;
    while(top<=right && left<=bottom)
    {
        for(int i=left;i<=right;i++)
            cout<<arr[top][i]<<" ";
        top++;
        for(int i=top;i<=bottom;i++)
            cout<<arr[i][right]<<" ";
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
                cout<<arr[bottom][i]<<" ";
            bottom--;
        }
        
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
                cout<<arr[i][left]<<" ";
            left++;
        }
    }
    
}
bool cmp(int a,int b)
    {
        return a>b;
    };

bool cmpp(const pair<int,int> &a, const pair<int,int>&b)
{
    return a.second < b.second;
}
int main()