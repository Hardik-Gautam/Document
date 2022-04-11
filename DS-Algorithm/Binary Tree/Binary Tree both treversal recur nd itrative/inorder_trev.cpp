#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node(int a)
    {
        data=a;
    }
    node *left=NULL;
    node *right=NULL;
};
// This is store the values
void inorderFill(node* root, vector<int> &v)
{
        if(root == nullptr)
            return;
        inorderFill(root->left, v);
        v.push_back(root->data);
        inorderFill(root->right, v);
}

// this is for print the values
void inorder_recursvely(node *root)
{
    if(root==NULL) return;
    inorder_recursvely(root->left);
    cout<<root->data<<" ";
    inorder_recursvely(root->right);
}

vector<int> inorder_itrative(node *root)
{
    vector<int> v;
    if(root==NULL) return v;
    
    stack<node*> st;
    node *crnt = root;

    while(crnt!=NULL || st.empty()==false)
    {
        while (crnt!=NULL)
        {
            st.push(crnt);
            crnt = crnt->left;
        }
        crnt = st.top();
               st.pop();
        v.push_back(crnt->data);
        crnt = crnt->right;
    }
    return v;
}


int main()
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

    // BOTH TREVERSAL 
    // vector<int> v = inorder_itrative(root);
    vector<int> v;
    inorderFill(root,v);
    
    for(int i:v)
        cout<<i<<" ";
    
    // inorder_recursvely(root);


    return 0;
}