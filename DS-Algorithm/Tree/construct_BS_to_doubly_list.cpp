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

node *Tree_to_Doubly_List(node *root)
{
    if(root==nullptr) return root;
    node *head = Tree_to_Doubly_List(root->left);
    static node *prev=NULL;

    if(prev==nullptr)
        head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    Tree_to_Doubly_List(root->right);
    return head;
}
void print_dlist(node *head)
{
    node *crnt=head;
    while(crnt!=NULL)
    {   
        cout<<crnt->data<<" ";
        crnt=crnt->right;
    }
}
int main()
{
    node *root=new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right=new node(4);
    root->right=new node(12);
    root->right->left=new node(7);
    node *head = Tree_to_Doubly_List(root);
    print_dlist(head);
    return 0;
}