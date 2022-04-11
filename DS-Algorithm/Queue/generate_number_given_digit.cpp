#include<bits\stdc++.h>
using namespace std;
void generate_number(string a, string b, int n)
{
    queue<string> q;
    q.push(a);
    q.push(b);
    for(int i=0;i<n;i++)
    {
        string s = q.front();
        cout<<s<<" ";
        q.pop();
        q.push(s+a);
        q.push(s+b);
    }
}
int main()
{
    generate_number("5","6",10);
    return 0;
}