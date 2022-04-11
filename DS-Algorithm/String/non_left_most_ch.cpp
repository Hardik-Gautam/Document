#include<bits\stdc++.h>
using namespace std;
/**
 * @brief I'm using three method to 
 * find the non left repeated charcter in given string
 * 1 brute force approch
 * 2 efficent one 
 * 3 efficent two
 */
// B F
int non_left_most_repeated(string s)
{
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        bool check=false;
        for(int j=0;j<n;j++)
            if(i!=j && s[i]==s[j])
                check = true;
        if(check==false)
            return i;
    }
    return -1;
}
// 1 E
int non_left_most_repeated1(string s)
{
    int arr[256]={0};
    int n = s.length();
    for(int i=0;i<n;i++)
        arr[s[i]]++;
    for(int i=0;i<n;i++)
        if(arr[s[i]]==1)
            return i;
    return -1;
}
// 2 E
int non_left_most_repeated2(string s)
{
    int arr[256]={0};
    int n = s.length();
    fill(arr,arr+256,-1);
    for(int i=0;i<n;i++)
    {
        if(arr[s[i]]==-1)
            arr[s[i]]=i;
        else
            arr[s[i]]=-2;
    }
    for(int i=0;i<n;i++)
        if(arr[s[i]]>=0)
            return arr[s[i]];
    return -1;
}
int main()
{
    string s = "geeksforgeeks";
    // cout<<non_left_most_repeated(s);
    // cout<<non_left_most_repeated1(s);
    cout<<non_left_most_repeated2(s);
    return 0;
}

