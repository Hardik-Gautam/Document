#include<bits\stdc++.h>
using namespace std;
struct node
{
    node *left,*right;
    int data;
    node(int a)
    {
        data = a;
        left=right=NULL;
    }
};
// Recursive solution 
int maxlevel=0;
void print_left_view(node *root, int level)
{
    if(root==NULL) return;
    if(maxlevel<level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    print_left_view(root->left,level+1);
    print_left_view(root->right,level+1);
}
// itrative solution :: it is working well to recursive solution
void print_left_view2(node *root)
{
    queue<node*> q;
    q.push(root);
    while(q.size()>0)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *crnt=q.front();
            q.pop();
            if(i%2==0)
                cout<<crnt->data<<" ";
            if(crnt->left!=NULL)q.push(crnt->left);
            if(crnt->right!=NULL)q.push(crnt->right);
        }

    }
}
int main()
{
    node *root=new node(10);
    root->left = new node(20);
    root->left->left = new node(40);
    root->left->right=new node(50);
    root->right=new node(30);
    root->right->left=new node(60);
    root->right->right=new node(70);
    print_left_view(root,1);
    // print_left_view2(root);
    return 0;
}