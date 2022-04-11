#include<bits\stdc++.h>
using namespace std;
bool check_van(string s1,string s2)
{
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1==s2);
}
bool check_vang(string s1, string s2)
{
    // we'll count the freq of both strings and then 
    // check them 
    int count[26]={0};
    int n =  s1.length();
    for(int i=0;i<n;i++)
    {
        count[s1[i]-'a']++;
        count[s2[i]-'a']--;
    }
    for(int i=0;i<n;i++)
        if(count[s1[i]-'a']!=0)
            return false;
    return true;
}
int main()
{
    string s1 = "listen";
    string s2 = "silent";
    cout<<check_van(s1,s2)<<endl;
    cout<<check_vang(s1,s2)<<endl;
    return 0;
}