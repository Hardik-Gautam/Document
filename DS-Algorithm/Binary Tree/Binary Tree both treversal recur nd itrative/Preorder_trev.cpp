#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node(int a)
    {
        data = a;
    }
    node *left=NULL;
    node *right=NULL;
};

// This is for print the values
void Preorder_recursvely(node *root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    Preorder_recursvely(root->left);
    Preorder_recursvely(root->right);
}

void Preorder_recursvely(node *root, vector<int> &v)
{
    if(root==NULL) return;
    v.push_back(root->data);
    Preorder_recursvely(root->left,v);
    Preorder_recursvely(root->right,v);
}

vector<int> itrative_preorder(node *root)
{
    vector<int> v;
    if(root==NULL) return v;
    
    stack<node*> st;

    st.push(root);
    while (st.empty()!=true)
    {
        node *item = st.top();
        st.pop();

        v.push_back(item->data);
        
        if(item->right!=NULL) st.push(item->right);
        if(item->left!=NULL) st.push(item->left);
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
    vector<int> v = itrative_preorder(root);    
    for(int i:v)
        cout<<i<<" ";

    Preorder_recursvely(root);
    return 0;
}
