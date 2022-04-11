#include<bits\stdc++.h>
using namespace std;

void freq(string s)
{
    int count[26]={0};// set all elemenet by zero
    for(int i=0;i<26;i++)
        count[s[i]-'a']++;
    for(int i=0;i<s.length();i++)
        if(count[s[i]-'a']>0)
            {cout<<s[i]<<" "<<count[s[i]-'a']<<endl;}
}

int main()
{
    string s="geeksforgeeks";
    freq(s);
    return 0;
}