#include<bits\stdc++.h>
using namespace std;

bool subsequcenc(string s1,string s2)
{
    int n = s1.length();
    int m = s2.length();
    int j=0;
    int i=0;
    while(i<n)
    {
        if(s1[i]==s2[j])
            j++;
        
        i++;    
    }
    return (j==m);
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "gexks"; // "geoks" try it
    cout<<subsequcenc(s1,s2)<<endl;
    return 0;
}