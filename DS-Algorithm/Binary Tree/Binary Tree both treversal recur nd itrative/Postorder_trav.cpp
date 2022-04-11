#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node (int a)
    {
        data=a;
    }
    node *left=NULL;
    node *right=NULL;
};

// This is for print
void Postorder_recursively(node *root)
{
    if(root==NULL) return;

    Postorder_recursively(root->left);
    Postorder_recursively(root->right);
    cout<<root->data<<" ";
}

// this is for store the values
void Postorder_recursively(node *root, vector<int> &v)
{
    if(root==NULL) return;

    Postorder_recursively(root->left,v);
    Postorder_recursively(root->right,v);
    v.push_back(root->data);
}


vector<int> Postorder_itrative(node *root)
{
    /*
        this itrative method is using two stack where st2 store 
        finall items of postorder
    */

    vector<int> v;
    if(root==NULL) return v;

    stack<node*> st1,st2;
    st1.push(root);

    while(st1.empty()!=true)
    {
        node *item = st1.top();
                     st1.pop();
              st2.push(item);
        if(item->left!=NULL) st1.push(item->left);
        if(item->right!=NULL) st1.push(item->right);
    }

    while(st2.empty()==false)
    {
        node *item = st2.top();
                     st2.pop();
        v.push_back(item->data);
    }

    return v;
}


int  main()
{
    // This is construct Tree
    /*
        Tree View
              1
            /   \
          2      3
        /   \   /  \
       4     5 6    7
       
    */
    
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // BOTH TRAVERSAL 
    vector<int> v = Postorder_itrative(root);
    for(int i:v)
        cout<<i<<" ";
    Postorder_recursively(root);
    
    return 0;
}