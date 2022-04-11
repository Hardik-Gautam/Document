#include<bits/stdc++.h>
using namespace std;
/**
 * this is Rabin karp algorithm use hash computation to 
 * find the next window by using previous windows computation
 * therefor it's better then navie solution in gernal case
 * but in worst case it's behave as navie algorithm
 * 
 * Let's consider we have given string is "abcdab"
 * and pattern is "abcde"
 * we use rolling method to calculate the hash coputation
 * 'd' is length of pattern :: d = 5 
 * a=1, b=2, c=3, d=4, e=5;
 * h("abc")
 */
#define d 256
const int q=101;

void RBSearch(string text,string ptrn)
{
    int n = text.length();
    int m = ptrn.length();

    //compute (d^(m-1))%q
    int h=1;
    for(int i=0;i<m-1;i++)
        h=(h*d)%q;
    
    // compute p and t
    int p=0,t=0;
    for(int i=0;i<m;i++)
    {
        p=(p*d+ptrn[i])%q;
        t=(t*d+text[i])%q;
    }
    for(int i=0;i<=(n-m);i++)
    {
        //check for hit
        if(p==t)
        {
            bool flag=true;
            for(int j=0;j<m;j++)
                if(text[i+j]!=ptrn[j])
                    {flag=false;break;}

            if(flag==true)
                cout<<i<<" "<<ptrn;
        }
        if(i<(n-m))
        {
            t = ((d*(t-text[i]*h))+text[i+m])%q;
            if(t<0)
                t=t+q;
        }
    }
}

int main()
{
    string txt="hello guys i am hardik may i know where are you from";
    string ptrn="hardik";
    RBSearch(txt,ptrn);
  
    return 0;
}
