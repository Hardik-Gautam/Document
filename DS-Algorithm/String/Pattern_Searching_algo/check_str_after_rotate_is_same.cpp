#include<bits/stdc++.h>
using namespace std;
/**
 * this question says if we have given a string s1
 * and another string s2 then check the s2 in s1 after left rotations
 * that s1 will become s2 or not after left rotations 
 * 
 * Trick: we'll concatinate the s1 string two times s1+s1 
 * and then we'll find the s2 string in s1+s1 if that is present 
 * then we'll return true otherwise false
 */

bool check_after_rotate(string s1,string s2)
{
    if((s1+s1).find(s2)==string::npos)
        return false;
    return((s1+s1).find(s2)!=string::npos);
}


int main()
{
    // this is true
    string s1="abcd";
    string s2="cdab";

    // this is false
    // string s1="abab";
    // string s2="abba";
    
    cout<<check_after_rotate(s1,s2);
    
    return 0;
}