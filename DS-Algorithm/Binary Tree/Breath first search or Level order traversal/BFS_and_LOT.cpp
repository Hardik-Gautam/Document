#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node(int a)
    {
        data = a;
    }
    node *left = NULL;
    node *right = NULL;
};

vector<int> Breath_first_search(node *root)
{
    vector<int> v;
    if(root==NULL) return v;

    queue<node*> q;
    q.push(root);
    while (q.empty()==false)
    {
        node *item = q.front();
        q.pop();
        v.push_back(item->data);
        if(item->left!=NULL) q.push(item->left);
        if(item->right!=NULL) q.push(item->right);
    }
    return v;
    
}

int main()
{
    /*
        Tree View 
            1
          /   \
         2     3
       / \    / \
      4  5   6   7

    */
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(6);

    vector<int> v = Breath_first_search(root);
    for(int i:v)
    cout<<i<<" ";

    return 0;
}