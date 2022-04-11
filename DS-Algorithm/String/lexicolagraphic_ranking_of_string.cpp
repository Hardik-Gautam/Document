#include<bits\stdc++.h>
using namespace std;
#define CHAR 256
#define Alphabet 26
int string_rank(string s)
{
    int n=s.length();
    int arr[CHAR]={0};
    long int fact[Alphabet];
    fact[0]=1;
    fact[1]=1;
    
    for(int i=2;i<Alphabet;i++) // factorial array
        fact[i]=i*fact[i-1];
    
    for(int i=0;i<n;i++)
        arr[s[i]]++;
    
    int output=0;
    int numberOfLetterSmaller;

    for(int i=0;i<n;i++)
    {
        numberOfLetterSmaller=0;
        for(int j=0;j<CHAR;j++)
        {
            if(j==s[i])
                break;
            if(arr[j])
                numberOfLetterSmaller++;
        }
        arr[s[i]]=0;
        output+=numberOfLetterSmaller*fact[n-1-i];
    }

    return output+1;    
}
int main()
{
    cout<<string_rank("ibytes");
    return 0;
}