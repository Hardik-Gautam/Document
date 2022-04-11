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
// O(n) time compelxity
int countNode(node *root)
{
    if(root==NULL)
        return 0;
    return 1+countNode(root->left)+countNode(root->right);
}
//0(n) time complexity
int countNode2(node *root)
{
    int lh=0,rh=0;
    node *crnt=root;
    while (crnt!=NULL)
    {
        lh++;
        crnt=crnt->left;
    }
    crnt=root;
    while (crnt!=NULL)
    {
        rh++;
        crnt=crnt->right;
    }
    if(lh==rh)
        return pow(2,lh)-1;
    
    return 1+countNode2(root->left)+countNode2(root->right);
    
}
int main()
{
    node *root=new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right=new node(4);
    // root->left->right->right=new node(12);
    root->right=new node(7);
    int size=countNode(root);
    // cout<<size<<endl;
    cout<<countNode2(root);


    return 0;
}