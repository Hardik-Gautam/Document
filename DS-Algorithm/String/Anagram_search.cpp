#include<bits\stdc++.h>
using namespace std;
/**
 * search an anagram is it's simlar like pattern searching 
 * condition character shoud be match only 
 * condition another diffrent char should not be present there
 * Example 1:
 * string s1 = "geeksforgeeks" 
 * string s2 = "frog" // bcs forg and frog char are same 
 * ans: yes  
 * Example 2:
 * string s1 = "geeksforgeeks" 
 * string s2 = "reek" // bcs g is coming among the rgeek
 * ans: no 
 */
#define CHAR 256

// bool arr_cmp(int arr1[],int arr2[])
// {
//     for(int i=0;i<CHAR;i++)
//         if(arr1[i]!=arr2[i])
//             return false;
//     return true;
// }

bool check_vanagram(string &s1, string &ptr, int j)
{
    int count[CHAR]={0};
    int n = s1.length(); // both string length are same
    for(int i=0;i<n;i++)
    {
        count[ptr[i]]++;
        count[s1[i+j]]--;
    }
    for(int i=0;i<CHAR;i++)
        if(count[i]!=0)
            return false;
    return true;
}
bool anagram_search(string &s1, string &ptr)
{
    int n = s1.length();
    int m = ptr.length();
    
    for(int i=0;i<=n-m;i++)
        if(check_vanagram(s1,ptr,i))
            return true;
       
    
    return false;
}   
int main()
{
    string s="geeksforgeeks";
    string ptr="forg";
    cout<<anagram_search(s,ptr);
    return 0;
}