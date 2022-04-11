#include<bits/stdc++.h>
using namespace std;
/**
 * this function will return the index of left first index 
 * occurence 
 * we are dicussing three approch here
 * Brute force 
 * efficent one
 * efficent two
 * @return int 
 */
//Brute Force O(n^2)
int left_most_in(string s)
{
    int n = s.length();

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(s[i]==s[j])
                return i;
    return 0;
}
//efficent one O(n) time and O(n) space
int left_most_in1(string s)
{
    int arr[256];
    int n = s.length();
    fill(arr,arr+256,-1);
    for(int i=0;i<n;i++)
    {
        if(arr[s[i]]==-1)
            arr[s[i]]=i;
        else
            return arr[s[i]];
    }
        
    return 0;
}
// efficent two o(n) time and o(n) but we're saving memory
int left_most_in2(string s)
{
    int n = s.length();
    bool arr[256];
    fill(arr,arr+256,false);
    int rs=0;
    while(n--)
    {
        if(arr[s[n]])
            rs = n; 
        else
            arr[s[n]]=true;
    }
    return rs;
}

int main()
{
    string s = "abcddcc";       
    // All are working well
    // cout<<left_most_in(s);
    // cout<<left_most_in1(s);
    // cout<<left_most_in2(s);

    return 0;
}