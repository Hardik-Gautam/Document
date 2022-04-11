#include<bits\stdc++.h>
using namespace std;
/**
 * @brief this imporved naive algorithm 
 * will work only if distic eletment are present in pattern string
 * this algorithm has Theta(n) time complexity and 
 * if given pattern is same length with given s string 
 * then it time complexity would be O(n^2) and 
 * O(1) space complexity of it
 */
void serach_pattern(string s, string p)
{
    int n=s.length();
    int m=p.length();
    for(int i=0;i<=n-m;)
    {
        int j;
        for(j=0;j<m;j++)
            if(p[j]!=s[i+j])
                break;
        if(j==m)
            cout<<i<<" ";
        if(j==0)
            i++;
        else
            i = (i+j);
    }
}

int main()
{
    string s="hfskalskabcgaeaesdf";
    string p="abc";
    serach_pattern(s,p);
    return 0;
}