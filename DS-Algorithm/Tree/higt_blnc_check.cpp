#include<bits\stdc++.h>
using namespace std;
struct node {
    node *left;
    node *right;
    int data;
    node(int a)
    {
        data=a;
        right=left=NULL;
    }

};

int isBalance(node *root)
{
    if(root==NULL) return 0;
    int lh = isBalance(root->left);
    if(lh==-1) return -1;
    int rh = isBalance(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) 
        return -1;
    else
        return max(lh,rh)+1;
}
int main()
{
    node *root=new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right=new node(4);
    root->right=new node(12);
    root->right->left=new node(7);
    // root->right->right=new node(5);
    if(isBalance(root)>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}