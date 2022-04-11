#include<bits/stdc++.h>
using namespace std;


/**
 * @brief This code is usefull to reverse a sentence
 * without any extra space like array or stack
 * it has O(n^2) time complexity and O(1) extra space
 * @param s this is our given string/sentence
 */
void reverse_word(string &s, int start, int end)
{
    while(start<=end)
    {
        swap(s[start],s[end]);
        start++;end--;
    }
}
void reverse_sentence(string &s)
{
    int n = s.length();
    int i=0;
    int j=0;
    while(j<n)
    {
        if(s[j]==' ')
        {
            reverse_word(s,i,j-1);
            i = j+1;
        }
        j++;
    }
    reverse_word(s,i,j-1);
    reverse_word(s,0,n-1);
}

int main()
{
    string s="Hello world This is my world";
    cout<<s<<endl;
    reverse_sentence(s);
    cout<<s<<endl;
    return 0;
}