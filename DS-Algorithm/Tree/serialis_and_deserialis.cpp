#include<bits\stdc++.h>
using namespace std;
struct node 
{
    int data;
    node *left,*right;
    node (int a)
    {
        data=a;
        left=right=NULL;
    }
};
void Serializ(node *root,vector<int> &v)
{
    if(root==NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    Serializ(root->left,v);
    Serializ(root->right,v);
}

//[10,11,12,NULL,14,NULL,15]
static int index=0;
node *Deserializ(vector<int> &v)
{
    if(index==v.size())
        return NULL;
    if(v[index]==-1)
        return NULL;
    node *root=new node(v[index]);
    index++;
    root->left=Deserializ(v);
    root->right=Deserializ(v);
    return root;
}
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(-1);
    v.push_back(14);
    v.push_back(-1);
    v.push_back(15);
    node *root=Deserializ(v);
    vector<int> s;
    Serializ(root,s);
    for(int i:s)
        cout<<i<<" ";
    return 0;
}