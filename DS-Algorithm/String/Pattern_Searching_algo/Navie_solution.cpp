#include<bits\stdc++.h>
using namespace std;
/**
 * @brief This is Navie
 * approch it has much time coplexity O(n-m)*m time complexity
 * but it has O(1) space complexity 
 * This algo work for both condition
 * if pattern string has repeated element or distic element
 * @param s this is given string where we have to search the all making pattern
 * @param ptrn this is pattern string which is find in the s given string
 */
void navie_pattern_search(string s, string ptrn)
{
    int n = s.length();
    int m = ptrn.length();
    //"hello hello" :input :len = 11
    //"ell":pattern : len = 3
    // 8 = 11-3 // 0 to 8 window will become by len of pattern
    for(int i=0;i<=n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)
            if(ptrn[j]!=s[i+j])
                break;
        if(j==m)
            cout<<i<<" ";
    }
    return;
}
int main()
{
    string s="geeksforgeeks";
    string p="ek";
    navie_pattern_search(s,p);
    return 0;
}