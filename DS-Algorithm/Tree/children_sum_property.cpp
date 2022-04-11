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
bool isSum(node *root)
{
    if(root==NULL) return 1;
    if(root->left==NULL && root->right==NULL) return 1;
    int sum=0;
    if(root->left!=NULL) {sum+=root->left->data;}
    if(root->right!=NULL){sum+=root->right->data;}
    return((sum == root->data)&& isSum(root->left) && isSum(root->right));
}
int main()
{
    node *root=new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right=new node(4);
    root->right=new node(12);
    root->right->left=new node(7);
    root->right->right=new node(5);
    
    if(isSum(root))
    {cout<<"true";}
    else
    {cout<<"false";};

    return 0;
}